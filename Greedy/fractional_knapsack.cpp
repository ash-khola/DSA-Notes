// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item.

static bool comp(Item a, Item b)
{
    return (a.value * 1.0) / a.weight > (b.value * 1.0) / b.weight;
}
// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, comp);

    double ans;

    for (int i = 0; i < n; i++)
    {
        if (W - arr[i].weight >= 0)
        {
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            ans += W * ((1.0) * arr[i].value / arr[i].weight);
            break;
        }
    }

    return ans;
}

// Time Complexity : O(NlogN)
// Auxilliary Space: O(1)