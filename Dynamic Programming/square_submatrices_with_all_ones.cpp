int countSquares(vector<vector<int>>& matrix) {
    int count = 0;

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 1) {
                if(i == 0 or j == 0) count++;
                else {
                    matrix[i][j]= min({matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]}) + 1;
                    count += matrix[i][j];
                }
            }
        }
    }

    return count;
}

// T.C: O(n)
// S.C: O(1)