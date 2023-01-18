// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long, vector<long>, greater<long>> pq;
    for (long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    if (pq.size() == 1)
    {
        return 0;
    }

    long a, b, sum = 0;
    while (pq.size() != 1)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        sum += (a + b);
        pq.push(a + b);
    }

    return sum;
}

// T.C - O(n * log(n))
// S.C = O(n)