// Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

unordered_map<int, int> mp;
int idx = 0;

Node *build(int pre[], int lower_bound, int upper_bound) {
    if(lower_bound > upper_bound) {     // we are maintaing lower_bound and upper_bound just for the base condition
        return NULL;
    } 

    Node *newNode = new Node(pre[idx++]);
//  above step can be replaced by newNode = new Node(in[lower_bound + ((higher_bound - lower_bound) / 2)]) we do this if we are asked to build tree without taking the help of preorder traversal but this will result in the formation of a general balanced tree so preorder vector and unordered_map is used to give proper structure to the desired tree, if preorder vector is not given than make the general balanced binary tree using in[mid]
    int mid = mp[newNode->data];
    // mid = lower_bound + ((higher_bound - lower_bound) / 2);

    newNode->left = build(pre, lower_bound, mid-1);
    newNode->right = build(pre, mid+1, upper_bound);

    return newNode;
}

Node *buildTree(int in[], int pre[], int n) {
    for(int i = 0; i<n; i++) {
        mp[in[i]] = i;
    }

    return build(pre, 0, n-1);
}