// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

// Solution:  https://youtu.be/bdxJHWIyyqI

long long divide(long long dividend, long long divisor)
{
    // code here
    bool neg = false;

    if ((dividend < 0 or divisor < 0) and (dividend > 0 or divisor > 0))
    {
        neg = true;
    }

    long long n = abs(dividend), m = abs(divisor);
    long long q = 0, t = 0;

    for (int i = 31; i >= 0; i--)
    {
        if (t + (m << i) <= n)
        {
            t += m << i;
            q = q | (1LL << i);
        }
    }

    if (neg)
    {
        q *= -1;
    }

    return q;
}

// Time Complexity: O(1)   --> As there will be only 32 iterations so it is constant time for all inputs
// Auxiliary Space: O(1)