// Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.

void inorder(vector<Node*> &in, Node *root)
{
    if(!root)
        return;
    
    inorder(in, root->left);
    in.push_back(root);
    inorder(in, root->right);
}

Node* solve(vector<Node*>in, int low, int high)
{
     if(low > high)
        return NULL;
    
    int mid = low + (high - low) / 2;
    Node *root = in[mid];
    
    root->left = solve(in, low, mid - 1);
    root->right = solve(in, mid + 1, high);
    
    return root;
}

Node* buildBalancedTree(Node *root)
{
	// Code here
	vector<Node *> in;
	inorder(in, root);
	return solve(in, 0, in.size()-1);
}