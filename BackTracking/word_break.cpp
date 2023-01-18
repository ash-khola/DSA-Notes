// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

// Soln.
// Particularly there is no backTracking step used anywhere but in the for loop of the partition program the if condition works as a backTracking step


vector<string> ans;

void partition(string str, string temp, unordered_set<string> &st)
{
    if (str.length() == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        string left = str.substr(0, i + 1);
        if (st.find(left) != st.end())
        {
            string right = str.substr(i + 1);
            if (temp.length() == 0)
                partition(right, temp + left, st);
            else
                partition(right, temp + " " + left, st);
        }
    }
}

vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    unordered_set<string> st;

    for (auto a : dict)
    {
        st.insert(a);
    }

    partition(s, "", st);
    return ans;
}