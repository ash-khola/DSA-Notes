// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
// You must find a solution with a memory complexity better than O(n2).

// Solution:

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int low = matrix[0][0], high = matrix[matrix.size() - 1][matrix.size() - 1];
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        int less_than_mid = 0;
        for(int i = 0; i < matrix.size(); i++) {
            less_than_mid += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        if(less_than_mid < k) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    
    return low;  // if the answer exist than low will be definately present in the matrix, and k - 1 elements sre going to be smaller than low.''
}

// T.C = log(n)(outer binary_search) * O(n)(inner for loop) * log(n)(upper bound)   =   O(n)*log(n)*log(n) 
// S.C = O(1)