// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Solution:
// It can be easly done in T.C of O(n * log(n)) but we should do it in a better T.C
// For that we will use a min/max heap as per the question (for smallest we use maxHeap and after filling the first k elements in it, we will compare all the remaining with the top of the maxHeap and if we found any smaller than the top then we will pop() the top element and insert arr[i], it is not necessary that the newly inserted elemented will be at the top only in the heap, the tree may rearrange itself as per the newly inserted element) and in largest element case we will use minHeap and insert those which wll be greater than the top element

// T.C  - O(K + (N-K) * Log K)  --> k to build heap from initial k elements and in the worst case (n-k) elements might need to be inserted in the heap, and for each it will be log(k) (as tree size is k only) T.C

int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    priority_queue<int> pq;

    for (int i = l; i <= r; i++)
    {
        if (i < k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }

    return pq.top();
}

// ************************** Similar Problem **************************

// Similar to above que there is one more que.
// K-th Largest Sum Contiguous Subarray

// You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.

int kthLargest(vector<int> &arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum = arr[i];
        if (pq.size() < K)
        {
            pq.push(sum);
        }
        else
        {
            if (pq.top() < sum)
            {
                pq.pop();
                pq.push(sum);
            }
        }

        for (int j = i + 1; j < N; j++)
        {
            sum += arr[j];
            if (pq.size() < K)
            {
                pq.push(sum);
            }
            else
            {
                if (pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}