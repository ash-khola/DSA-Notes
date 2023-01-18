// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

// Solution:
// Cam be solved easily using recursion, but here we are using bit magic for the same

vector<string> AllPossibleStrings(string s)
{
    // Code here
    int n = s.length();
    vector<string> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp += s[j];
            }
        }

        if (temp.length())
        {
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// Time Complexity: O(2^n * n) where n is the length of the String (if we solve it recursively than T.C will be O(2^n))
// Space Complexity: O(n * 2n)