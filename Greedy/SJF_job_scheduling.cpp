// The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. SJN, also known as Shortest Job Next (SJN), can be preemptive or non-preemptive.

// Solution:

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)  // sort on basis of lower arrival time
{
    if (a[1] == b[1])          // if(arrival time is same than sort for lower burst time)
    {
        return a[2] < b[2];
    }

    return a[1] < b[1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> job(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int temp;
                cin >> temp;
                job[i].push_back(temp);
            }
        }

        sort(job.begin(), job.end(), comp);   // sorting on basis of arrival time
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({job[0][2], job[0][1], job[0][0]});            // pushing on basis of burst time

        vector<int> ans;
        int cur_time = 0, burst_time, i = 1;

        while (!pq.empty())
        {
            burst_time = pq.top()[0];
            ans.push_back(pq.top()[2]);
            pq.pop();

            cur_time += burst_time;

            while (true)
            {
                if (i < n and job[i][1] <= cur_time)
                {
                    pq.push({job[i][2], job[i][1], job[i][0]});
                    i++;
                }
                else
                {
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

// Time complexity: O(n * log(n))