// Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
// Note: All elements of this array should be part of exactly one partition.

// Solution:

bool solve(int a[], int n, int cur_sum, int target_sum, int cur_sets, int k, vector<int> &vis)
{
    if (cur_sets == k - 1)
    {
        return true;
    }

    if (cur_sum == target_sum)
    {
        if (solve(a, n, 0, target_sum, cur_sets + 1, k, vis))
        {
            return true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            if (solve(a, n, cur_sum + a[i], target_sum, cur_sets, k, vis))
            {
                return true;
            }
            vis[i] = 0;
        }
    }

    return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % k != 0)
    {
        return false;
    }

    vector<int> vis(n, 0);
    return solve(a, n, 0, sum / k, 0, k, vis);
}