// Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

// Solution:
class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class comparator
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<node *, vector<node *>, comparator> pq;
        int maxi = INT_MIN, mini = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            int element = KSortedArray[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            pq.push(new node(element, i, 0));
        }

        int start = mini, end = maxi;

        while (!pq.empty())
        {
            node *temp = pq.top();
            pq.pop();

            mini = temp->data;

            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            if (temp->col + 1 < n)
            {
                maxi = max(KSortedArray[temp->row][temp->col + 1], maxi);
                pq.push(new node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else
            {
                break;
            }
        }

        pair<int, int> ans;
        ans = {start, end};

        return ans;
    }
};

// Time Complexity : O(n * k *log k)     n*k is the total elements and we need to insert almost all of them once in the queue.
// Auxilliary Space  : O(k)             // The size of queue will never exceed k