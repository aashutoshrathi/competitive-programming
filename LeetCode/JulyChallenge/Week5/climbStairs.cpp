class Solution {
public:
    int climbStairs(int n) {
        double a = 1.61803398875;
        double b = 2.23606797749;
        return (pow(a, n + 1) - pow((-1.0 / a), n + 1)) / b;
    }
};
