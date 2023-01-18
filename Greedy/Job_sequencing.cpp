// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

// Solution:
static bool comp(Job a, Job b)
{
    if (a.profit < b.profit)
    {
        return false; // jo chij chahiye vahi return kardo return a.p
    }

    return true;
}

vector<int> JobScheduling(Job arr[], int n)
{
    bool done[n + 1] = {false};
    sort(arr, arr + n, comp);
    int mprof = 0, jb = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int d = arr[i].dead;

        for (int j = min(n, arr[i].dead); j >= 1; j--)
        {
            if (done[j] == false)
            {
                done[j] = true;
                mprof += arr[i].profit;
                jb++;
                break;
            }
        }
    }

    ans.push_back(jb);
    ans.push_back(mprof);
    return ans;
}

// Time Complexity: O(NlogN)
// Auxilliary Space: O(N)
