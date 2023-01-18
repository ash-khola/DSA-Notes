// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

// Solution:
// The naive solution will be in two for loops with time complexity O(n*k)
// Next optimised one will be using priority queue with time complexity O(n*log(k)) and S.C - O(k).
// And the final optimised solution will be using deque with T.C O(n) as we are traversing through the array only once and in deque also we are dealing with all the elements only once and the space complexity will be O(k) because elements in the deque van never be more than k

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    deque<int> dq;
    vector<int> ans;
    int i = 0;

    for (; i < k - 1; i++)
    {
        while (!dq.empty() and arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (; i < n; i++)
    {
        while (!dq.empty() and dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        while (!dq.empty() and arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    return ans;
}