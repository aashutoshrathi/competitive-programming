class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        int tXor = 0; // will contain XOR of both numbers
        for(int i: nums)
            tXor ^= i;
        
        int rightMost = tXor & ~(tXor - 1);
                
        for(int i: nums) {
            if(i & rightMost)
                a ^= i;
            else
                b ^= i;
        }
        
        return {a, b};
    }
};
