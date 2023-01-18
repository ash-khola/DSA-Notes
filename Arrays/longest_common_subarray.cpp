// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
//         Sliding Window technique
        
//         int maxRepeated = 0;
        
//         for(int i = -n + 1; i < m; i++) {
//             int count = 0;
//             for(int j = 0; j < n; j++) {
//                 if(i+j < 0) continue;
//                 else if(i + j >= m) break;
//                 else if(nums1[i + j] == nums2[j]) {
//                     count++;
//                     maxRepeated = max(count, maxRepeated);
//                 }
//                 else count = 0;
//             }
//         }
        
//         return maxRepeated;
        
//      dp technique, similar as longest common subsequence
        
        int maxRepeated = 0;
        vector<vector<int>> dp(n + 1 ,vector<int> (m  + 1, 0));
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = 0;
                
                maxRepeated = max(maxRepeated, dp[i][j]);
            }
        }
        
        return maxRepeated; 
    }
};

// Sliding Window
// T.C -> O(O(N + M) * N)
// S.C -> O(1)

// DP
// T.C -> O(N*M)
// S.C -> O(N)