// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Solution:
// Can be solved using simple dp approach but the T.C will be O(n^2), here the index of dp array is itself equal to the length of the increasing subsequence

int lengthOfLIS(vector<int> &nums)
{
    vectorr<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > temp.back()) temp.push_back(nums[i]), len++;
        else {
            int idx = lower_bound(nums.begin(), nums.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }

    return len;
}

// T.C : O(n * log(n))   // lower_bound ----> O(log(n))
// s.C : O(n)