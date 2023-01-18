// You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

// 0 means the cell is empty, so you can pass through,
// 1 means the cell contains a cherry that you can pick up and pass through, or
// -1 means the cell contains a thorn that blocks your way.
// Return the maximum number of cherries you can collect by following the rules below:

// Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
// After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
// When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
// If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

// Solution:
// This problem is similar to two persons starting from (0, 0) and reaching (n-1, n-1), the maximum of their sum is the ans.
// This can also be solved by backTracking by first reaching at the bottom and returning back, but it will give T.L.E

class Solution {
public:
    int dp[50][50][50];

    int collect(vector<vector<int>> &grid, int r1, int c1, int r2, int n) {
        int c2 = r1 + c1 - r2;

        if(r1 >= n or r2 >= n or c1 >= n or c2 >= n or grid[r1][c1] == -1 or grid[r2][c2] == -1) return INT_MIN;

        if(r1 == n-1 and c1 == n-1) return grid[n-1][n-1];

        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int cherries = 0;

        if(r1 != r2) cherries += grid[r1][c1] + grid[r2][c2];
        else cherries += grid[r1][c1];

        int rr = collect(grid, r1, c1 + 1, r2, n);
        int rd = collect(grid, r1, c1 + 1, r2 + 1, n);
        int dr = collect(grid, r1 + 1, c1, r2, n);
        int dd = collect(grid, r1 + 1, c1, r2 + 1, n);

        return dp[r1][c1][r2] = cherries + max({rr, rd, dr, dd});
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int cherries = collect(grid, 0, 0, 0, grid.size());
        if(cherries > 0) return cherries;
        else return 0;
    }
};

// T.C: O(n^3) --> filling 3D D.P