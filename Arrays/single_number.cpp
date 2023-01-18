// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitFreq[32];
        memset(bitFreq, 0, sizeof(bitFreq));
        
        for(int it : nums) {
            for(int i = 0; i < 32; i++) {
                if(it&(1 << i)) bitFreq[i]++;
            }
        }
        
        int single = 0;
        
        for(int i = 0; i < 32; i++) {
            if(bitFreq[i] % 3 == 1) {
                single += 1 << i;
            }
        }
        
        return single;
    }
};

// T.C = O(n) * O(32)  =  O(n)
// S.C = O(1)