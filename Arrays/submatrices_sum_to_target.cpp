// Given a matrix and a target, return the number of non-empty submatrices that sum to target.
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

class Solution {
public:
    int subArraySum(vector<int> &arr, int target) {
        int count = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp[sum - target]) count += mp[sum - target];
            mp[sum]++;
        }

        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& grid, int target) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            vector<int> rowSum(grid[0].size(), 0);
            for(int j = i; j < grid.size(); j++) {
                for(int k = 0; k < grid[0].size(); k++) {
                    rowSum[k] += grid[j][k];
                }
                ans += subArraySum(rowSum, target);
            }
        }

        return ans;
    }
};

// T.C: O(n^2 * log(n))
// S.C: O(n)