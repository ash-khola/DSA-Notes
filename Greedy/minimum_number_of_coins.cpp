// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
// Find the minimum number of coins and/or notes needed to make the change for Rs N.

vector<int> minPartition(int N)
{
    // code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> res;

    int i = coins.size() - 1;  // can also start from i = 0, just reverse coins vector
    while (N)
    {
        if (coins[i] > N)
        {
            i--;
        }
        else
        {
            res.push_back(coins[i]);
            N -= coins[i];
        }
    }

    return res;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)