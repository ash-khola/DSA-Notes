// Given an array representation of min Heap, convert it to max Heap.

// Approach: Simply build a maxHeap from the bottom of the minHeap using heapify approach and heapify all the internal nodes in bottom up way.

void heapify(long arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n and arr[largest] < arr[l])
    {
        largest = l;
    }

    if (r < n and arr[largest] < arr[r])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void minHeapToMaxHeap(long *arr, int n)
{
    // Write your code here
    int startIndx = n / 2;

    for (int i = startIndx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Time Complexity to build a heap - O(n)
// Space Complexity - O(1)