// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Solution:  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/758462/c-detail-explain-diagram/?orderBy=most_votes

class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* build(vector<int> &inorder, int inLow, int inHigh, vector<int> &postorder, int poLow, int poHigh) {
        if(inLow > inHigh or poLow > poHigh) return nullptr;   // any one of the condition will also work
        
        TreeNode *newNode = new TreeNode(postorder[poHigh]);
        int leftSideOfIn = mp[postorder[poHigh]] - inLow;

        newNode->left = build(inorder, inLow, mp[postorder[poHigh]] - 1, postorder, poLow, poLow + leftSideOfIn - 1);
        newNode->right = build(inorder, mp[postorder[poHigh]] + 1, inHigh, postorder, poLow + leftSideOfIn, poHigh - 1);

        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        return build(inorder, 0, n-1, postorder, 0, n-1);
    }
};