// Given a binary tree, find if it is height balanced or not.
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

// Solution

bool ans = true;

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
    {
        ans = false;
    }

    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    height(root);
    return ans;
}