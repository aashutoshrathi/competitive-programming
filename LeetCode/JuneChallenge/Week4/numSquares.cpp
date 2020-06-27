#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 1. DP Approach
    int numSquares(int n) {
        vector<int> ways(n+1);
        // fill ways[i] = i;
        iota(ways.begin(), ways.end(), 0);
        
        for(int i=4; i <= n; i++) {
            int floor_root = floor(sqrt(n));
            for(int j=1; j*j <= i; j++)
                ways[i] = min(ways[i], ways[i-(j*j)] + 1);
        }

        return ways[n];
    }

    // 2. Pure Math (0ms, Source: LC Dicussions)
    // As per https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
    // Every number can be represented as sum of 4 perfect sq.

    bool checkSq(int n) {
        int floor_root = floor(sqrt(n));
        return (floor_root * floor_root) == n;
    }

    int numSquares(int n) {
        int froot = floor(sqrt(n));
        if(checkSq(n))
            return 1;
        
        for(int i=1; i <= froot; i++)
            if(checkSq(n - i*i))
                return 2;
        
        while(!(n%4))
            n >>= 2;
    
        return 3 + (n%8 == 7);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->numSquares(12) << endl;
    cout << s->numSquares(13) << endl;
    cout << s->numSquares(14) << endl;
    cout << s->numSquares(15) << endl;
    return 0;
}