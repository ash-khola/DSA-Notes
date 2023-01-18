// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
// Design an algorithm that runs in less than O(n) time complexity.

class Solution {
private:
    int leftHeight(TreeNode *root) {
        int hght = 0;
        TreeNode *copy = root;
        
        while(copy){
            copy = copy->left;
            hght++;
        }

        return hght;
    }

    int rightHeight(TreeNode *root) {
        int hght = 0;
        TreeNode *copy = root;

        while(copy) {
            copy = copy->right;
            hght++;
        }

        return hght;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = leftHeight(root), rh = rightHeight(root);
        if(lh == rh) return pow(2, lh) - 1; 
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// T.C : O(log(n)) --> means height of binary tree
// S.C : O(1)