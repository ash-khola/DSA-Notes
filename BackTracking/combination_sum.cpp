// Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

// Note:
// 1. All numbers will be positive integers.
// 2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// 3. The combinations themselves must be sorted in ascending order.

// Solution:

vector<vector<int>> ans;

void solve(vector<int> &A, int sum, int i, int b, vector<int> &temp)
{

    if (i >= A.size())
    {
        if (sum == b)
        {
            ans.push_back(temp);
        }
        return;
    }

    if (sum + A[i] <= b)
    {
        temp.push_back(A[i]);
        solve(A, sum + A[i], i, b, temp);
        temp.pop_back();
    }

    solve(A, sum, i + 1, b, temp);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    // Your code here
    vector<int> temp;
    sort(A.begin(), A.end());
    auto it = unique(A.begin(), A.end());

    A.resize(distance(A.begin(), it));
    solve(A, 0, 0, B, temp);
    
    return ans;
}