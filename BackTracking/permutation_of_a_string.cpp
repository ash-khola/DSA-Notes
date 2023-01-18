// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

// Solution:
class Solution
{
    // This is the optimised soluton, there is one more solution which can be done using extra map space

public:
    vector<string> ans;
    set<string> st;  // Set have been used to avoid copies of a string otherwise copies will be there because string may contain multiple frequencies of a single letter

    void swap(string &str, int i, int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    void permute(string &str, int ind)
    {
        if (ind == str.length())
        {
            st.insert(str);
            return;
        }

        for (int i = ind; i < str.length(); i++)
        {
            swap(str, ind, i);
            permute(str, ind + 1);
            swap(str, ind, i);
        }
    }
    vector<string> find_permutation(string S)
    {
        // Code here there
        permute(S, 0);

        for (auto a : st)
        {
            ans.push_back(a);
        }
        return ans;
    }
};