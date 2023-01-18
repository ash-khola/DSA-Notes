// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

int size(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + size(root->left) + size(root->right);
}

bool checkHeap(Node *root, int n, int index)
{
    if (!root)
    {
        return true;
    }

    if (index >= n)
    {
        return false;
    }

    if ((root->left and root->data < root->left->data) or (root->right and root->data < root->right->data))
    {
        return false;
    }

    return checkHeap(root->left, n, 2 * index + 1) & checkHeap(root->right, n, 2 * index + 2);
}

bool isHeap(struct Node *tree)
{
    int n = size(tree);
    return checkHeap(tree, n, 0);
}

// Time Complexity: O(N)
// Space Complexity: O(N)