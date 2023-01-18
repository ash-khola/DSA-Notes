// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Solution:

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> mp;
    long long max_len = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    
    for(int i = 0; i < nums.size(); i++) {
        if(mp[nums[i] - 1]) {
            continue;
        }
        else {
            long long count = 0;
            int streak = nums[i];
            
            while(mp[streak]) {
                streak++;
                count++;
            }
            
            max_len = max(max_len, count);
        }
    }
    
    return max_len;
}

T.C: O(n)