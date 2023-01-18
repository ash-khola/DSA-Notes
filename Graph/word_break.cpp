// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.\\

// Solution:

//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<string, int> dp;
    unordered_set<string> st;
    
    int solve(string check)
    {
        int siz = check.length();
        
        if(siz==0)
            return  1;
            
        if(dp[check]!=0)
            return dp[check];
            
        for(int i=1; i<=siz; i++)
        {
            string s = check.substr(0,i);
            if(st.find(s)!=st.end())
            {
                int x = solve(check.substr(i, siz-i));
                if(x==1)
                return dp[check] = 1;
            }
        }
        
        return dp[check] = -1;
    }
    
    int wordBreak(string A, vector<string> &B) {

        for(int i=0; i<B.size(); i++)
        {
            st.insert(B[i]);
        }
        
        int ans = solve(A);
        if(ans==1)
            return 1;
        return 0;
    }
};
