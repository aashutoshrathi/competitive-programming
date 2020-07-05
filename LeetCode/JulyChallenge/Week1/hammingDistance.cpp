class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        long long bAnd = x^y;
        for(int i=31; i>=0 && bAnd; i++) {
            res += bAnd%2; bAnd/=2;
        }
        return res;
    }
};
