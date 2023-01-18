// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

// Intuition
// Use merge Sort.

// Complexity
// Time complexity: O(n * log(n))
// Space complexity: O(n)
// Code:

class Solution {
public:
    vector<int> smaller;
    
    void merge(vector<pair<int, int>> &vec, int low, int mid, int high) {
        int i = low, j = mid+1, k = 0;
        vector<pair<int, int>> temp;
        
        while(i <= mid and j <= high) {
            if(vec[i] > vec[j]) {
                smaller[vec[i].second] += high - j + 1;
                temp.push_back(vec[i++]);
            }
            else temp.push_back(vec[j++]);
        }
        
        while(i <= mid) temp.push_back(vec[i++]);
        
        while(j <= high) temp.push_back(vec[j++]);
                
        for(int i = 0; i < temp.size(); i++) vec[low++] = temp[i];
    }
    
    void mergeSort(vector<pair<int, int>> &vec, int low, int high) {
        if(low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(vec, low, mid);
            mergeSort(vec, mid+1, high);
            merge(vec, low, mid, high);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        smaller.resize(nums.size(), 0);
        vector<pair<int, int>> vec(nums.size());

        for(int i = 0; i < nums.size(); i++) vec[i] = {nums[i], i};
        mergeSort(vec, 0, nums.size() - 1);
        
        return smaller;
    }
};