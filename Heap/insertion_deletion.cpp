class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // T.C of insertion - O(log(n))
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // T.C of deletion - O(log(n))
    // 1st version of delete function
    void delete ()
    {
        arr[1] = arr[n];
        n--;

        int index = 1;
        int largest = index;

        while (true)
        {
            int l = 2 * index;
            int r = 2 * index + 1;

            if (l > n)
            {
                break;
            }

            if (arr[l] > arr[largest])
            {
                largest = l;
            }

            if (r <= n and arr[r] > arr[largest])
            {
                largest = r;
            }

            if (largest != index)
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else
            {
                break;
            }
        }

        return;
    }

    // 2nd version of delete function using using heapify function
    void delete ()
    {
        swap(arr[1], arr[n]);
        n--;

        heapify(1);
    }

    void heapify(int arr[], int N, int i)
    {
        int largest = i;
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l <= n and arr[larges] < arr[l])
        {
            largest = l;
        }

        if (r <= n and arr[largest] < arr[r])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(largest, i);
            heapify(arr, largest, n);
        }
    }

    // For minHeap
    void heapify(int arr[], int N, int i)
    {
        int smallest = i;
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l <= n and arr[smallest] > arr[l])
        {
            smallest = l;
        }

        if (r <= n and arr[smallest] > arr[r])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(smallest, i);
            heapify(arr, smallest, n);
        }
    }

    // Note if 0 base indexing is used than l = 2*i + 1 and r = 2*i + 2 also conditions will be l < n (not equal to) and r < n.
};

// This function is used to build a heap from a normal array
// T.C of transforming the array into heap array = O(n)
void buildHeap(int arr[], int N)
{
    int startIndx = N / 2;

    for (int i = startIndx; i >= 1; i++)
    {
        heapify(arr, N, int i);
    }
}

// If we want to retrieve elements from the heap array in ascending oe descending order than it will take O(nlog(n)) time.