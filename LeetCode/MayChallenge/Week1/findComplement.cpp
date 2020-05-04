class Solution {
public:
    int findComplement(int num) {
        int x = log2(num) + 1; 
        bitset<32> b(num); 
        for (int i = 0; i < x; i++)  
            b.flip(i);
        
        return b.to_ulong();
    }
};
