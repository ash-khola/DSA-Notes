// Given two integers N and K. Find the kth permutation sequence of first N natural numbers.

// Solution:

string kthPermutation(int n, int k)
{
    // code here
    int fact = 1;
    vector<int> numbers;
    string str;

    for (int i = 1; i < n; i++)
    {
        numbers.push_back(i);
        fact *= i;
    }
    numbers.push_back(n);
    k = k - 1;

    while (true)
    {
        str += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }

        k = k % fact;
        fact /= numbers.size();
    }

    return str;
}