// Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

// Solution:

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> vis(nums.size(), 0);
        int tot_sum = accumulate(nums.begin(), nums.end(), tot_sum);
        if(k > nums.size() or tot_sum % k) return false;
        return backTrack(nums, vis, tot_sum / k, 0, 0, k);
    }
    
    bool backTrack(vector<int> &nums, vector<int> &vis, int target, int cur_sum, int idx, int k) {
        if(k == 1) return true;
        
        if(idx >= nums.size() or cur_sum > target) return false;
        
        if(cur_sum == target) return backTrack(nums, vis, target, 0, 0, k - 1);


        for(int i = idx; i < nums.size(); i++) {
            if(vis[i] == 1 or nums[i] + cur_sum > target) continue;
            
            vis[i] = 1;
            if(backTrack(nums, vis, target, cur_sum + nums[i], i + 1, k)) return true;
            vis[i] = 0;
        }
        
        return false;

        // We can also do it recursively like below, but recursive calls will be more time consuming than iteration.
        // bool a = false, b = false;

        // a = backTrack(nums, vis, target, cur_sum, idx + 1, k);
        // if(!vis[idx]) {
        //     vis[idx] = 1;
        //     b = backTrack(nums, vis, target, cur_sum + nums[idx], idx + 1, k);
        //     vis[idx] = 0;
        // }

        // return a|b;
    }
};