// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

// Solution:

class Solution {
public:
    // This function counts the number of subarrays having unique elements less than equal to k. 
    int kUniqueSubarrayCount(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int unique = 0;
        int j = 0;
        int total = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(!mp[nums[i]]) {
                mp[nums[i]]++;
                unique++;
            }
            else mp[nums[i]]++;
            if(unique <= k) total += i - j + 1;
            else {
                while(j <= i and unique > k) {
                    mp[nums[j]]--;
                    if(!mp[nums[j]]) {
                        unique--;
                    }
                    j++;
                }

                total += i - j + 1;
            }
        }

        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kUniqueSubarrayCount(nums, k) - kUniqueSubarrayCount(nums, k - 1);
    }
};