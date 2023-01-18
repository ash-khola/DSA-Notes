// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


// Solution; 
// Approach: Simple DFS but instead of making use of visited vector, we can simply make grid[i][j] = '0' after visiting it

void dfs(vector<vector<char>> &grid, int row, int col) {
    if(row < 0 or row >= grid.size() or col < 0 or col >= grid[0].size() or grid[row][col] == '0') {
        return;
    }
    
    grid[row][col] = '0';
    
    dfs(grid, row+1, col);
    dfs(grid, row-1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
    
    return;
}

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;     
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j);
                islands++;
            }
        }
    }
    
    return islands;
}

// T.C : O(n)
// S.C : O(1)