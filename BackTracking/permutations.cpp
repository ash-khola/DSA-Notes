// When all elements are unique.

class Solution {
private:
    vector<vector<int>> permutes;
    
    void makePermutes(vector<int> &nums, int idx) {
        if(idx == nums.size()) {
            permutes.push_back(nums);
            return;
        }
        
        for(int j = idx; j < nums.size(); j++) {
            swap(nums[idx], nums[j]);
            makePermutes(nums, idx + 1);
            swap(nums[idx], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        makePermutes(nums, 0);
        return permutes;
    }
};

// T.C = O(n!)
// S.C = O(n)   // stackFrame space


// *******************************When duplicate elements are also present in the array. *******************************

class Solution {
private:
    vector<vector<int>> permutes;
    
    void makePermutes(vector<int> &nums, int idx) {
        if(idx == nums.size()) {
            permutes.push_back(nums);
            return;
        }
        
        // unordered_map<int, int> mp;
        unordered_set<int> st;   //to avoid the repetition of same element at the idx
        
        for(int j = idx; j < nums.size(); j++) {
            // if(mp[nums[j]] != 0) continue;
            if(st.find(nums[j]) != st.()) continue;
            
            st.insert(nums[j]);
            // mp[nums[j]]++;
            swap(nums[idx], nums[j]);
            makePermutes(nums, idx + 1);
            swap(nums[idx], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.());
        makePermutes(nums, 0);
        return permutes;
    }
};


// T.C = O(n!)
// S.C = O(n)   // stackFrame space