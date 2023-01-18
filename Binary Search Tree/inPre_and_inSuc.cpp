// There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Solution:

Node * inSuc(Node *root)
{
    Node *root1=root;
    root1=root1->right;
    while(root1->left)
        root1=root1->left;
    return root1;
}

Node* inPre(Node *root)
{
    Node *root1=root;
    root1=root1->left;
    while(root1->right)
        root1=root1->right;
    return root1;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here

    if(!root)
        return;
    else if(root->key==key)
    {
        if(root->left)
        pre=inPre(root);
        if(root->right)
        suc=inSuc(root);
    }
    else if(root->key>key)
    {
        suc=root;
        findPreSuc(root->left, pre, suc, key);
    }
    else 
    {
        pre=root;
        findPreSuc(root->right, pre, suc, key);
    }

}