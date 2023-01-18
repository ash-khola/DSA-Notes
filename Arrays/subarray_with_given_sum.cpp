// Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
// In case of multiple subarrays, return the subarray which comes first on moving from left to right.

// Solution:

vector<int> subarraySum(int arr[], int n, int targetSum) {
    int curSum = 0;
    int start = 0, end = - 1;
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        curSum += arr[i];

        while(curSum > targetSum and start < i) {   // i - 1 is used because there should be atleast one element in the subarray, it can't be empty
            curSum -= arr[start++];
        }

        if(curSum == targetSum) {
            end = i;
            break;
        }
    }

    if(end == -1) {
        ans.push_back(-1);
    }

    else {
        ans.push_back(start + 1);  // one  based indexing used to give the answer
        ans.push_back(end + 1);
    }

    return ans;
}

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)