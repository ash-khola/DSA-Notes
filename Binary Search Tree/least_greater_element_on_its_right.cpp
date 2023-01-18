// Given an array arr[] of N integers and replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1. 

// Solution:
// Can be easily solved using set but we can think of a different approach using BST, it is nothing but the inorder Successsor of all the nodes of a tree

// Steps
// 1. We need to travese the tree in reverse direction so that we can find the next greater element whose index is greater than the index of the current, not smaller than it.
// 2. At eash iteration first find the inorder successor of that element in the tree, then insert the element in the tree.

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

public:

int succ = -1;

void inSucc(Node *root, int key) {   // finding the inorder successor of key in the tree
    if(!root) {
        return;
    }
    if(root->data <= key) {
        inSucc(root->right, key);
    }
    else if(root->data > key) {
        succ = root->data;
        inSucc(root->left, key);
    }
}

Node* insert(Node *root, int key) {    // inserting new element in the tree
    if(!root) {
        Node *newNode = new Node;
        newNode->data = key;
        return newNode;
    }
    
    if(root->data <= key) {
        root->right = insert(root->right, key);
    }
    else {
        root->left = insert(root->left, key);
    }
    
    return root;
}

vector<int> findLeastGreater(vector<int>& arr, int n) {
    Node *root = new Node;
    root->data = arr[n-1];
    root->left = NULL;
    root->right = NULL;
    vector<int> ans(n);
    
    ans[n-1] = -1;
    
    for(int i = n-2; i>=0; i--) {
        succ = -1;  // in case we don't get any value, -1 will be the successor
        inSucc(root, arr[i]);    // finding inSucc
        ans[i] = succ;        // filling elements in the tree
        insert(root, arr[i]);   // inserting the current element in the tree
    }
    
    return ans;
}