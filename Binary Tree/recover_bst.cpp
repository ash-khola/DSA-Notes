// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

// Solution:

class Solution {
private:
    TreeNode *first = NULL, *second = NULL, *third = NULL;
    TreeNode *prev = NULL;
public:
    void inorder(TreeNode *root) {
        if(!root) return;
        inorder(root->left);
        if(prev and root->val < prev->val) {
            if(first and second) third = root;
            else first = prev, second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first and third) swap(first->val, third->val);
        else swap(first->val, second->val);
    }
};

// T.C: O(n)
// S.C: O(1) (stackFrame ignored)