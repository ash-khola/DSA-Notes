// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Solution:

// int maxSize = 0;  // maxSize variable is not storing answer for this code, answer will be fetched from the ans vector only 

vector<int> find_largest(Node *root) {
    if(!root) {
        return {1, 0, INT_MAX, INT_MIN};  // if any of the left or right subtree of a node is NULL then only this consition hits else in other cases the control wil not reach on this base case
    }
    
    if(!root->left and !root->right) {
        return {1, 1, root->data, root->data};   // base case if node is a leaf node
    }

    vector<int> left_status = find_largest(root->left);
    vector<int> right_status = find_largest(root->right);

    if((left_status[0] == 1 and right_status[0] == 1) and (root->data > left_status[3] and root->data < right_status[2])) {
        if(left_status[2] == INT_MAX) {left_status[2] = root->data;}     // if the left sub tree is NULL
        if(right_status[3] == INT_MIN) {right_status[3] = root->data;}   // if the right subtree is NULL
        
        // maxSize = max(maxSize, left_status[1] + right_status[1] + 1);   // this is nkot working don't know why
        return {1, left_status[1] + right_status[1] + 1, left_status[2], right_status[3]};
    }
    else {
        return {0, max(left_status[1], right_status[1]), left_status[2], right_status[3]};
    }
}

int largestBst(Node *root) {
    // maxSize = 0;
    vector<int> ans = find_largest(root);

    return ans[1];
    // return maxSize;  // maxsize is not working in this case, don't know why, so
}