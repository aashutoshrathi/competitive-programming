#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
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
};

int main() {
    Solution *s = new Solution();
    cout << s->numSquares(12) << endl;
    cout << s->numSquares(13) << endl;
    cout << s->numSquares(14) << endl;
    cout << s->numSquares(15) << endl;
    return 0;
}