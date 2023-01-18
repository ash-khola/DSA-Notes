// *********************** Coin Change - 1 ****************************

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

class Solution {
public:
    int dp[10001];
    
    int solve(vector<int> &coins, int left_amount) {
        if(left_amount == 0) {
            return 0;
        }
        
        if(dp[left_amount] != -1) {
            return dp[left_amount];
        }
        
        int ans = INT_MAX - 1;
        
        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] <= left_amount) ans = min(ans, solve(coins, left_amount - coins[i]) + 1);
        }
        
        return dp[left_amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount);
        
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};

// T.C : O(amount)
// S.C : O(amount)

// *********************** Coin Change - 2 ****************************

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

class Solution {
public:

    int combi(vector<int> &coins, int target, int idx, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(target < 0 or idx < 0) return 0;
        
        if(dp[target][idx] != -1) return dp[target][idx];
        
        int no_move = combi(coins, target - coins[idx], idx, dp);
        int move = combi(coins, target, idx - 1, dp);
        
        return dp[target][idx] = no_move + move;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int> (coins.size(), -1));
        return combi(coins, amount, coins.size() - 1, dp);
    }
};

// T.C : O(amount * size of coins vector)
// S.C : O(amount * size of coins vector)
