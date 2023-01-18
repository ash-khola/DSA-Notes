// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.

// Solution:

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        int maxLen = 1;

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[j] + 1 == dp[i]) count[i] += count[j];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        int lis = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(dp[i] == maxLen) lis += count[i];
        }

        return lis;
    }
};

// T.C: O(n^2)
// S.C = O(n)