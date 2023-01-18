// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Solution:

class Solution {
public:
    int partition(vector<int> &arr, int idx, int k, vector<int> &dp) {
        if(idx >= arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int max_ele = INT_MIN, n = arr.size(), sum = 0;
        for(int i = idx; i < min(n, idx + k); i++) {
            max_ele = max(max_ele, arr[i]);
            sum = max(max_ele * (i - idx + 1) + partition(arr, i + 1, k, dp), sum);
        }

        return dp[idx] = sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return partition(arr, 0, k, dp);
    }
}

// Time complexity: O(n) because we are using 1 - D dp only.
// Space complexity: O(n) for making dp array