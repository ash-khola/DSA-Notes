// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Solution:

class Solution {
public:
    int BinarySearch(vector<int> &nums, int target, int tog) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low  + (high - low) / 2;
            
            if(target < nums[mid]) {
                high = mid - 1;
            }
            else if(target > nums[mid]) {
                low = mid + 1;
            }
            else {
                ans = mid;
                if(tog == -1) high = mid - 1;
                else low = mid + 1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = BinarySearch(nums, target, -1);
        int end = BinarySearch(nums, target, 1);
        vector<int> ans;
        
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;
    }
};