// Design a data structure to find the frequency of a given value in a given subarray.

// The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

// Implement the RangeFreqQuery class:

// RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
// int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
// A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).

// Solution:
class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(mp[value].begin(), mp[value].end(), right) - lower_bound(mp[value].begin(), mp[value].end(), left);
    }
};

// T.C: O(log(n)) for each query