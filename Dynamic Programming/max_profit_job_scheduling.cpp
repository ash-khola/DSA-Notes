// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

// Solution:
// We will sort the array in increasing endTime than will use dp approach to find the maxProfit which we can make by either include or excluding the current elemet, we will look all elements previous to the current element and find the job which has the nearest endTime to the current job using Binary Search (as Array is sorted) and then compare wheteher it is benefical to take it or not, if we don't take than simply fill the dp[i] with dp[i - 1], else dp[i] = current_profit + profit of nearest previous job.

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
        
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);

        for(int i = 0; i < n; i++) jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end(), comp);

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for(int i = 1; i < n; i++) {
            int low = 0, high = i - 1;
            int include = jobs[i][2];
            int last = -1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(jobs[mid][1] <= jobs[i][0]) {
                    last = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }

            if(last != -1) include += dp[last];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }

        return dp[n - 1];
    }
};