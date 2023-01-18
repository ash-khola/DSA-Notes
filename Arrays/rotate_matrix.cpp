// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Solution:
// Approach: First find the transpose if the matrix and then reverse each row of the matrix and you will get the matrix rotated.

void rotate(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {        // finding transpose
        for(int j = i + 1; j < matrix[0].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for(int i = 0; i < matrix.size(); i++) {      // reversing all rows
        reverse(matrix[i].begin(), matrix[i].end());
    }
}