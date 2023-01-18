// Given the root of a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.
// A BST is defined as follows:

// Solution:
bool ans = true;
int prev = INT_MIN;

void inorder(Node *root) {
    if(!root or !ans) {
        return;
    }

    inorder(root->left);

    if(prev < 0) {
        prev = root->data;
    }
    else {
        if(root->data < prev) {
            ans = false;
            return;
        }
        else {
            prev = root->data;
        }
    }

    inorder(root->right);

    return;
}

bool isBST (Node *root) {
    inorder(root);

    return ans;
}

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).