// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums

// Solution: 
// Approach: After finding the mid we will first see that in which how the array has beendivided by the mid, than according to that we will compare target and nums[mid] 

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(nums[mid] == target) {
            return mid;
        }
        
        if(nums[mid] >= nums[low]) {     
            if(target < nums[mid] and target >= nums[low]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(target > nums[mid] and target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}

// T.C : O(log(n))
// S.C : O(1)