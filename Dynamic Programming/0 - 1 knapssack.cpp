// Top down approach using recursion

int solve(vector<vector<int>> &dp, int wt[], int val[], int index, int weight_left) {
    if(index < 0) {
        return 0;
    }

    if(dp[weight-left][index] != -1) {
        return dp[weight_left][index];
    }

    if(weight_left >= wt[index]) {
        int take = val[index] + solve(dp, wt, val, index - 1, weight_left - wt[index]);
        int not_take = solve(dp, wt, val, index - 1, weight_left);

        return dp[weight_left][index] = max(take, not_take);
    }

    else {
        int not_take = solve(dp, wt, val, index - 1, weight_left);
        return dp[weight_left][index] = not_take;
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(W, vector<int> (n, -1));
    int index = n-1;

    return solve(dp, wt, val, index, W);
}


// Bottom up approach using tabular method

int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>> dp(W+1, vector<int> (n + 1, -1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            else {
                if(j >= wt[i-1]) {
                    dp[i][j] = max(dp[i-1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
                else {
                    dp[i][j]  = dp[i-1][j];
                }
            }
        }
    }

    return dp[n][W];
}

// For both the methods:
// Expected Time Complexity: O(N*W)  but tabular method will run faster because there are no recursive function calls in that
// Expected Auxiliary Space: O(N*W)