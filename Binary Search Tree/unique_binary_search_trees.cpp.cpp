// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Solution
// summatio(1 to n) --> (f[i] = f[i - 1] + f[n - i])  recurrence realation

class Solution {
public:
    int numTrees(int n) {        
        vector<int> dp(20, 0);      // 20 was given in l.C test cases

        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) dp[i] += dp[j - 1] * dp[i - j];
        }

        return dp[n];
    }
};

// T.C: O(n^2)
// S.c: O(n)