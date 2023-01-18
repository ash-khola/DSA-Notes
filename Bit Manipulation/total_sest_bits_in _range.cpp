// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Solution:
// Formula : 2^(x - 1) + (n - 2^x +1) + solve(n - 2^x)  [x = nearest power of 2 of the given number]
int countSetBits(int n)
{
    // Your logic here
    if (n == 0)
    {
        return 0;
    }
    int nearest_power_of_two = log2(n);

    return pow(2, nearest_power_of_two - 1) * (nearest_power_of_two) + (n - pow(2, nearest_power_of_two) + 1) + countSetBits(n - pow(2, nearest_power_of_two));
}

// Time Complexity: O(log N).