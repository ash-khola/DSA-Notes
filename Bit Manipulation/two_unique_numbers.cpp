// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

// Solution: 
// 1. XOR all so we get  the xor of the two unique no's
// 2. Find the right most set bit of the total xor
// 3. Separately calculte the xor of numbers with the same right most set bit as of total xor and the ones which don't have that bit as  set bit
// 4. We got our answer in step 3 

vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int a = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        a = a xor nums[i];
    }

    int unique_xor = 1;

    while (true)
    {
        if (unique_xor & a)
        {
            break;
        }

        unique_xor = unique_xor << 1;
    }

    int c = 0, d = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (unique_xor & nums[i])
        {
            c = c xor nums[i];
        }
        else
        {
            d = d xor nums[i];
        }
    }

    vector<int> ans;

    ans.push_back(min(c, d));
    ans.push_back(max(c, d));

    return ans;
}