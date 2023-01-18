// Given a binary tree and two node values your task is to find the minimum distance between them.
// The given two nodes are guaranteed to be in the binary tree.

// Solution:
// Formula used: (dist of n1 from lca) + (distance of n2 from lca) - 2

Node* lca(Node *root, int a, int b) {
    if(!root) {
        return NULL;
    }

    if(root->data == a or root->data == b) {
        return root->data;
    }

    Node *found_on_left = lca(root->left, a, b);
    Node *found_on_right = lca(root->right, a, b);

    if(found_on_left and found_on_right) {
        return root;           // lca found
    }

    else if(found_on_left) {
        return found_on_left;
    }

    else if(found_on_right) {
        return found_on_right;
    }

    else {
        return NULL;
    }
} 

int distance_from_lca(Node *root, int a) {
    if(!root) {
        return 0;
    }

    if(root->data == a) {
        return 1;          // this is the one which for wich we are doing -2 after adding dist1 and dist2
    }

    int left = distance_from_lca(root->left, a);
    int right = distance_fromt_lca(root->right, a);

    if(!left and !right) {
        return 0;
    }

    return 1 + max(left, right);
}

int findDist(Node *rootl, int n1, int n2) {
    Node *ancestor = lca(root, n1, n2);
    int dist1 = distance(root, n1);
    int dist2 = distance(root, n2);

    return (dist1 + dist2 - 2);
}