class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ptr = digits.size() - 1;
        int carry = 1;
        while(carry && ptr >= 0) {
            digits[ptr]++;
            carry = digits[ptr]/10;
            if(digits[ptr] > 9) {
                digits[ptr] = digits[ptr]%10;
            }
            if(carry && ptr >= 0)
                ptr--;
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
