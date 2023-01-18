// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

// Soln.
// Simple backTracking problem, we have to check all the possible ways to n queens in the grid, we will backTrack after returning from the recursive stackFrame by unplacing the queen from a particular grid, and to reduce the time complexity we are using the lower_diag, left_diag and upper_diag, before placing a queen in any grid we will check whether it is safe to place there or not with the helpo of these vectors

vector<vector<int>> ans;
void place(vector<vector<int>> &mat, vector<int> &temp, vector<int> &upper_diag, vector<int> &lower_diag, vector<int> &left_row, int col, int size)
{
    if (col == size)
    {
        ans.push_back(temp);
        return;
    }

    int n = size;

    for (int i = 0; i < n; i++)
    {
        if (upper_diag[i + col] == 0 and left_row[i] == 0 and lower_diag[n - 1 + (col - i)] == 0)
        {
            mat[i][col] = 1;
            temp.push_back(i + 1);
            upper_diag[i + col] = 1;
            left_row[i] = 1;
            lower_diag[n - 1 + (col - i)] = 1;
            place(mat, temp, upper_diag, lower_diag, left_row, col + 1, size);
            mat[i][col] = 0;
            temp.pop_back();
            upper_diag[i + col] = 0;
            left_row[i] = 0;
            lower_diag[n - 1 + (col - i)] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    // code here
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<int> temp, left_row(n, 0), upper_diag(2 * n - 1, 0), lower_diag(2 * n - 1, 0);
    place(mat, temp, upper_diag, lower_diag, left_row, 0, n);

    return ans;
}