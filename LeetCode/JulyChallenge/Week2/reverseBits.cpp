class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> b(n);
        
        for(int i=0; i<16; i++) {
            bool t = b[i];
            b[i] = b[32-i-1];
            b[32-i-1] = t;   
        }
        return b.to_ulong();
    }
};
