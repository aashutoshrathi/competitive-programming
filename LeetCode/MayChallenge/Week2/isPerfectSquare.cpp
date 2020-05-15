class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1; // as n*n = sum(odd)
        while(num > 0) {
            num -= i;
            i+=2;
        }
        return num == 0;
    }
};