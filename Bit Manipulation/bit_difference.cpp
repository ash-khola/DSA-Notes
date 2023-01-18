// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

// Solution
int countBitsFlip(int a, int b)
{

    // Your logic here
    int xr = a xor b;
    int cnt = 0;

    while (xr)
    {
        if (xr & 1)
        {
            cnt++;
        }
        xr = xr >> 1;
    }

    return cnt;
}

// Time Complexity - O(log(max(a,b)))  // it is the time complexity of the while loop because the no. of bits in the while loop will only be log(max(a, b))