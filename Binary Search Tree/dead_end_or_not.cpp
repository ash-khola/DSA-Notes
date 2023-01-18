// Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

// Solution: 
// Approach: Here we will constraint the possible data value of a node in a specific range, and at any instant if we found that the lower_bound is equal to upper_bound then it means that the data value of the node itself is equal to root->data == lower_bound == upper_bound, and we cannot build tree further as no data range is left for other values to be inserted.

bool dead_end = false;

void solve(Node *root, int lower_bound, int upper_bound) {
    if(!root) {
        return;
    }
    
    if(lower_bound == upper_bound) {
        dead_end = true;
        return;
    }
    
    solve(root->left, lower_bound, root->data - 1);
    solve(root->right, root->data + 1, upper_bound);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    dead_end = false;
    solve(root, 1, INT_MAX);
    
    return dead_end;
}