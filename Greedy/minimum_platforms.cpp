// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 0;
    int j = 0;
    int cnt = 0, ans = 0;

    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            ans = max(cnt, ans);
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
    }

    return ans;
}

// Time Complexity: O(nLogn)
// Auxiliary Space: O(n)