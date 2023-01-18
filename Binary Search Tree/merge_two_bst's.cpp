// Givent the root nodes of two binary trees you nedd to mergr them into a single binary tree.

// Solution:
// Approach 1: It is very easy to make a new tree from the inorder traversal of both the trees
// Approach 2: Make the inorder traversals of both the trees and combine them into a single sorted one, and do balance BST on the sorted final inorder vector

void inorder(Node *root, vector<Node *> &in) {
    if(!root) {
        return;
    }
    
    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
    
    return;
}

Node* balanceBST(vector<Node *> &final_in, int low, int high) {
    if(low > high) {
        return NULL;
    }
    
    int mid = low + (high - low)/2;
    Node *root = final_in[mid];
    
    root->left = balanceBST(final_in, low, mid - 1);
    root->right = balanceBST(final_in, mid + 1, high);
    
    return root;
} 

void merge(Node *root1, Node *root2)
{
    vector<Node*> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);
    
    vector<Node *> final_in;        
    int i = 0, j = 0;
    
    while(i < in1.size() and j < in2.size()) {
        if(in1[i]->data <= in2[j]->data) {
            final_in.push_back(in1[i++]);
        }
        else {
            final_in.push_back(in2[j++]);
        }
    }
    
    while(i < in1.size()) {
        final_in.push_back(in1[i++]);
    }
    
    while(j < in2.size()) {
        final_in.push_back(in2[j++]);
    }
    
    Node *root = balanceBST(final_in, 0, final_in.size() - 1);   // here we will get our tree merged
}