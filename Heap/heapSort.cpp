// Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

// 0 based indexing have been used here

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

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

void buildHeap(int arr[], int n)
{
    int startIndx = n / 2;

    for (int i = startIndx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

//  Here in heapSort we are one by one taking the largest elemnent in the heap at the rear end of the array so the array is geting sorted in increasing order
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);  // here we got our largest element at the top of the array

    while (n > 1)
    {
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }
}