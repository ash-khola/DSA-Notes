// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
// In simple way longest path b/w two leaf nodes

// Solution
int ans = INT_MIN;

int solve(Node* node) {
    if(node == NULL) {
        return 0;
    }

    int left_height = solve(node->left);
    int right_height = solve(node->right);

    ans = max(left_height + right_height + 1, ans);    // if you don't maintain ans then it will be a simple code for   finding hewight of tree 

    return max(left_height, right_height) + 1;
}

int diameter(Node* node) {

    solve(node);
    return ans;
}