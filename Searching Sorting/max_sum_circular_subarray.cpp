// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

// Solution:

class Solution {
public:
    int kAlgo(vector<int> &nums) {
        int curSum = 0, maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            maxSum = max(curSum, maxSum);
            if(curSum < 0) curSum = 0;
        }

        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = kAlgo(nums);
        if(maxSum < 0) return maxSum;  // if all the elements of array are less than 0

        int totSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            totSum += nums[i];        // calculating total Sum of vector 
            nums[i] *= -1;            // and negating all the elements
        }

        int minSum = kAlgo(nums);     // finding maximum sum subarray of negated vector i.e the minimum sum subarray of original vector

        return max(maxSum, totSum - (-minSum));   // max of simple kadane on original or totalSum - minimum sum subarray
    }
};

// T.C = O(n)
// S.C = O(1)