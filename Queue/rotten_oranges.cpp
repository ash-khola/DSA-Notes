// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

// Solutiion:


int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    queue<pair<int, int>> q;
    
    for(int i =0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int tim = 0;  // answer is stored in this
    
    while (!q.empty()) {
        int rotten_oranges_in_queue = q.size();
        int count = 0;   // it is necessary, beacuse it is not guaranteed that the elements present in the queue will rott their nearby oranges, it might be the case that all oranges nearby to all the oranges are already rotten or empty cell then their is no need for the next cycle that's why we have taken count variable

        for (int i = 0; i < rotten_oranges_in_queue; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row - 1 >= 0 and grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                q.push({row - 1, col});
                count++;
            }

            if (col - 1 >= 0 and grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                q.push({row, col - 1});
                count++;
            }

            if (row + 1 < grid.size() and grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                q.push({row + 1, col});
                count++;
            }

            if (col + 1 < grid[0].size() and grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                q.push({row, col + 1});
                count++;
            }
        }

        tim += min(count, 1);
    }
    
    return tim;
}

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n)