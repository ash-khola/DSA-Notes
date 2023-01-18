// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
// A subarray is a contiguous part of an array.

// Solution:
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size(), minLen = INT_MAX;
        vector<long long> prefixSum(n, 0);

        for(int i = 0; i < n; i++) {
            if(i == 0) prefixSum[i] = nums[i];
            else prefixSum[i] = prefixSum[i - 1] + nums[i];
            if(prefixSum[i] >= k){
                minLen = min(minLen,i+1);
            }
            while(!dq.empty() and prefixSum[dq.back()] >= prefixSum[i]) dq.pop_back();
            while(!dq.empty() and prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};