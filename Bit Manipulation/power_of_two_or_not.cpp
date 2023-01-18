// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

// Solution:
bool isPowerofTwo(long long n)
{

    if (n == 0)
    {
        return false;
    }
    // long long np = log2(n);        // T.C - O(log(n))
    // Method 1:
    // if(pow(2, np) == n) {
    //     return true;
    // }
    // return false;

    // Method 2:                      // T.C - O(log(n))
    // long long x = 1;

    // while(np) {      // this can be done in single step also if np is small like (1<<np)
    //     x = x<<1;
    //     np--;
    // }

    // if(x == n) {
    //     return true;
    // }
    // return false;

    // Method 3:
    return (n & (n - 1)) == 0; // T.C - O(1)
}