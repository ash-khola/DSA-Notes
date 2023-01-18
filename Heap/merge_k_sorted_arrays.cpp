// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

class element
{
public:
    int row;
    int col;
    int val;

    element(int row, int col, int val)
    {
        this->row = row;
        this->col = col;
        this->val = val;
    }
};

struct comparator
{
    bool operator()(element a, element b)
    {
        return a.val > b.val;
    }
};

class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<element, vector<element>, comparator> pq;
        vector<int> ans;
        for (int i = 0; i < K; i++)
        {
            pq.push(element(i, 0, arr[i][0]));
        }

        while (!pq.empty())
        {
            element temp = pq.top();
            pq.pop();
            ans.push_back(arr[temp.row][temp.col]);
            temp.col++;

            if (temp.col < K)
            {
                pq.push(element(temp.row, temp.col, arr[temp.row][temp.col]));
            }
        }

        return ans;
    }
};

// Time Complexity: O(K2*Log(K))
// Auxiliary Space: O(K)  //we are not consodering the ans vector