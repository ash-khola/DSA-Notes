// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totSum = 0;
        totSum = accumulate(cardPoints.begin(), cardPoints.end(), totSum);
        
        if(k == cardPoints.size()) return totSum;
        
        int sum = 0, n = cardPoints.size(), min_win = INT_MAX, win = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            sum += cardPoints[i];
            win++;
            if(win >= n - k) {
                cout<<"Here" <<endl;
                min_win = min(min_win, sum);
                sum -= cardPoints[start++];
            }
        }
        
        return totSum - min_win;
    }
};

// T.C = O(n)
// S.C = O(1)