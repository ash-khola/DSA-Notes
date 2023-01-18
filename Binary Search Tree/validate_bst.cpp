// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// Solution: Simply do inorder traversal and check whethter current node->val is greter than previous value or not.

class Solution {
public:
    bool ans = true;
    long long prev = LLONG_MIN;
    bool flag = true;

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);

        if(root->val <= prev) {
            ans = false;
            return;
        }

        prev = root->val;

        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

// T.C : O(n)
// S.C: O(log(n))-->stackFrame space