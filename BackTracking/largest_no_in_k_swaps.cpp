// Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

// Solution:
void solve(string str, string &max, int k, int ind, int n)
{
    if (k == 0)
    {
        return;
    }

    char maxChar = str[ind];
    for (int i = ind + 1; i < n; i++)
    {
        if (str[i] > maxChar)
        {
            maxChar = str[i];
        }
    }

    if (maxChar != str[ind])
    {
        k--;
    }

    for (int i = ind; i < n; i++)
    {
        if (str[i] == maxChar)
        {
            swap(str[i], str[ind]);
            if (str > max)
            {
                max = str;
            }
            solve(str, max, k, ind + 1, n);
            swap(str[i], str[ind]);
        }
    }
}

string findMaximumNum(string str, int k)
{
    // code here.
    string max = str;
    int n = str.length();
    solve(str, max, k, 0, n);

    return max;
}