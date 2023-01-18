// Given a undirected graph, you need to check if there exists a path where the length of the path is more than k
// Note: There should not be any cycle in the graph

// Solution: This is a simle bavkTracking Question, in which we will try all paths and will when we don't find a answer or we find an answer we will simply backTrack and the backTracking step will be simply unmarking the path vector, so that we can again go through that point to explore more paths.

bool dfs(vector<pair<int, int>> adj[], int key, int sum, int k, vector<int> &path)
{
    if (sum > k)
    {
        return true;
    }
    path[key] = 1;

    for (auto a : adj[key])
    {
        if (!path[a.first])
        {
            if (dfs(adj, a.first, sum + a.second, k, path))
            {
                return true;
            }
        }
    }

    path[key] = 0;
    return false;
}
string pathMoreThanK(int n, int m, int k, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<pair<int, int>> adj[n];
    vector<int> path(n, 0);

    for (auto a : edges)
    {
        adj[a[0]].push_back({a[1], a[2]});
        adj[a[1]].push_back({a[0], a[2]});
    }

    if (dfs(adj, 0, 0, k, path))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}