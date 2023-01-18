// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

// solution:

bool isValid(int grid[9][9], int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == val)
        {
            return false;
        }

        if (grid[i][col] == val)
        {
            return false;
        }

        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }

    return true;
}

bool solve(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isValid(grid, i, j, k))
                    {
                        grid[i][j] = k;
                        if (solve(grid) == true)
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

bool SolveSudoku(int grid[N][N])
{
    // Your code here
    return solve(grid);
}

// Function to print grids of the Sudoku.
// It will be called only when we return true form SolveSudoku function
void printGrid(int grid[N][N])
{
    // Your code here
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        // cout<<endl;
    }
}