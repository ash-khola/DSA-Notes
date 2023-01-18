// Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
int maxSize = 0, minSize = 0;
void insertHeap(int &x)
{
    maxHeap.push(x);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    minSize++;
    balanceHeaps();
}

// Function to balance heaps.
void balanceHeaps()
{
    if (maxSize < minSize)
    {
        maxHeap.push(minHeap.top());
        maxSize++;
        minHeap.pop();
        minSize--;
    }
}

// Function to return Median.
double getMedian()
{
    if ((maxSize + minSize) & 1)
    {
        return maxHeap.top();
    }
    else
    {
        return (maxHeap.top() + minHeap.top()) / 2;
    }
}

// Time Complexity : O(nlogn)
// Auxilliary Space : O(n)