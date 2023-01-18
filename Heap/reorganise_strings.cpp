// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.

// Solution;
// Copy the max_freq characters at the even indexes and if still even remains vacan then fill those with the other remaining elements and once even indexes are over than start filling the odd indexes with the remaining elements.
// T.C - O(n)
// S.C - O(n)

string reorganizeString(string s)
{
    map<char, int> mp;
    int max_freq = INT_MIN;
    char max_char;
    int n = s.length();

    for (auto a : s)
    {
        mp[a]++;
        if (max_freq < mp[a])
        {
            max_freq = max(max_freq, mp[a]);
            max_char = a;
        }
    }

    if (max_freq > (s.length() + 1) / 2)
    {
        return "";
    }

    int i = 0;
    for (i = 0; i < s.length(); i++)
    {

        if (i % 2 == 0)
        {
            if (max_freq == 0)
            {
                break;
            }
            s[i] = max_char;
            max_freq--;
            mp[max_char]--;
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (i >= n)
        {
            i = 1;
        }
        while (mp[ch])
        {
            s[i] = ch;
            mp[ch]--;
            i += 2;
            if (i >= n)
            {
                i = 1;
            }
        }
    }

    return s;
}