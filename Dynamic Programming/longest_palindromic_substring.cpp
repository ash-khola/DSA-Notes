class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        int size = s.length();
        vector<vector<int>> dp(size, vector<int>(size,-1)); //it is very important to initialize vector like this, otherwiae it will throw some invalid memory reference error
        
        for(int g=0; g<s.length(); g++)
        {
            for(int i = 0, j = g; j<size; i++, j++)
            {
                if(g == 0)
                {
                    dp[i][j] = 1;
                }
                else if(g == 1 and s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j] and dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                
                if (dp[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};