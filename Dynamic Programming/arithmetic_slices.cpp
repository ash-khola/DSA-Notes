// An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
// Given an integer array nums, return the number of arithmetic subarrays of nums.

// A subarray is a contiguous subsequence of the array.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return 0;

        int prev = 0;

        int count = 0;

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i-2]) {
                prev = prev + 1;
            }
            else {
                prev = 0;
            }

            count += prev;
        }

        return count;
    }
};

// T.C : O(n)
// S.C : O(1)