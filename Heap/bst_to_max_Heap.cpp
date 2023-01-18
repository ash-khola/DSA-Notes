// Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap

void inorder(Node *root, vector<int> &order)
{
    if (!root)
    {
        return;
    }

    inorder(root->left, order);
    order.push_back(root->data);
    inorder(root->right, order);
}

void postOrder(Node *root, vector<int> &order, int &index)
{
    if (!root)
    {
        return;
    }

    postOrder(root->left, order, index);
    postOrder(root->right, order, index);
    root->data = order[index++];

    return;
}

void convertToMaxHeapUtil(Node *root)
{
    // Your code goes here
    vector<int> order;
    inorder(root, order);
    int index = 0;
    postOrder(root, order, index);

    return;
}

// Time Complexity : O(n)
// Auxiliary Space : O(n)