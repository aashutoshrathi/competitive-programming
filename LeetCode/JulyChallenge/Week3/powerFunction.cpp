class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0 || x == 1.0)
            return 1.0;
        if(n < 0)
            return myPow(1/x, -n);
        return (n % 2 ? x : 1)*myPow(x*x, n/2);
    }
};
