// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Solution:

class Solution {
public:
    // D.P solution:

    // int solve(TreeNode *root, unordered_map<TreeNode *, int> &dp) {
    //     if(!root) return 0;

    //     if(dp.count(root)) return dp[root];

    //     int take = 0, not_take = 0;
    //     if(root->left and root->right) take = root->val + solve(root->left->left, dp)+ solve(root->left->right, dp) + solve(root->right->right, dp) + solve(root->right->left, dp);
    //     else if(root->left) take = root->val + solve(root->left->left, dp) + solve(root->left->right, dp);
    //     else if(root->right) take = root->val + solve(root->right->left, dp) + solve(root->right->right, dp);
    //     else take = root->val;

    //     not_take = solve(root->left, dp) + solve(root->right, dp);

    //     return dp[root] = max(take, not_take);
    // }

    // *****************************************

    // Without D.P

    pair<int, int> solve(TreeNode *root) {
        if(!root) return {0, 0};
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int rob = root->val + left.second + right.second;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, not_rob};
    }

    int rob(TreeNode* root) {
        // unordered_map<TreeNode *, int> dp;
        pair<int, int> result = solve(root);
        return max(result.first, result.second);  
    }
};