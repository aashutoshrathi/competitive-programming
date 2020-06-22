#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        for(int i = 0; i <= K+1; i++) {
            dp[i][src] = 0;
        }
        
        for(int i = 1; i <= K+1; i++) {
            for(auto j: flights) { 
                if(dp[i-1][j[0]] != INT_MAX)
                    dp[i][j[1]] = min(dp[i][j[1]], dp[i-1][j[0]] + j[2]);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX) ? -1 : dp[K+1][dst];
    }
};