// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

// Solution:

class Solution {
private:
    TreeNode *curr = new TreeNode(-1);
public:
    void inorder(TreeNode *root) {
        if(!root) return;
        inorder(root->left);
        curr->right = root;
        curr = curr->right;
        curr->left = NULL;
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = curr;
        inorder(root);
        return ans->right;
    }
};