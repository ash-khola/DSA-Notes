// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

// Solution:
// When its your turn do the best, and when others turn assume the worst

class Solution {
public:
    int dp[20][20];
    int findWinner(vector<int> &nums, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = nums[i] + min(findWinner(nums, i + 2, j), findWinner(nums, i + 1, j - 1));
        int right = nums[j] + min(findWinner(nums, i + 1, j - 1), findWinner(nums, i, j - 2));

        return dp[i][j] = max(left, right);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        memset(dp, -1, sizeof(dp));
        return 2 * findWinner(nums, 0, nums.size() - 1) >= sum;
    }
};

// T.C: O(n^2)