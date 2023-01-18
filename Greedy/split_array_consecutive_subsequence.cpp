// You are given an integer array nums that is sorted in non-decreasing order.

// Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

// Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
// All subsequences have a length of 3 or more.
// Return true if you can split nums according to the above conditions, or false otherwise.

// A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

// Solution:
// If no subsequence formed from current element than form new suseq. by consuming next two consecutive elements also and also indicate the need of the next element which can be accomodated in this subsequence, else if there is a need of current element in any of the previously formed subsequences then use it there and increment the need of next consecutive element.

bool isPossible(vector<int>& nums) {
    unordered_map<int, int> freq, need;

    for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;

    for(int i = 0; i < nums.size(); i++) {
        if(!freq[nums[i]]) continue;

        if(need[nums[i]]) {
            freq[nums[i]]--;
            need[nums[i]]--;
            need[nums[i] + 1]++;
        }

        else if(freq[nums[i] + 1] and freq[nums[i] + 2]) {
            freq[nums[i]]--;
            freq[nums[i] + 1]--;
            freq[nums[i] + 2]--;
            need[nums[i] + 3]++;
        }

        else return false;
    }

    return true;
}

// T.C: O(n)