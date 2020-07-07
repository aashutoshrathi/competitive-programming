class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + ((long long) n << 3)))/2;
    }
};