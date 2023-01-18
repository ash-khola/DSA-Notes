// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

// Solution:
// Start from top right corner.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        
        while(row <= matrix.size() - 1 and col >= 0) {
            if(target == matrix[row][col]) return true;
            
            if(target < matrix[row][col]) col--;
            else row++;
        }
        
        return false;
    }
};