// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Solution;

// Intuition
// Count the cases (nums[i] > 2 * nums[j]) while doing merge sort on the given array.
// Approach :
// Similar to count inversion problem, just a little modification in Merge Sort.
// Complexity
// Time complexity: O(n * log(n))
// Space complexity: O(n)
// Code
class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high) {
        int i = low, j = mid + 1;
        vector<int> temp;
        int count = 0;

        for(i = low; i <= mid; i++) {
            while(j <= high and nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1); 
        }

        i = low, j = mid + 1;

        while(i <= mid and j <= high) {
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= high) temp.push_back(nums[j++]);

        for(i = 0; i < temp.size(); i++) nums[low++] = temp[i];

        return count; 
    }

    int mergeSort(vector<int> &nums, int low, int high) {
        int count = 0;
        if(low < high) {
            int mid = low + (high - low) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, high);
            count += merge(nums, low, mid, high);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};