#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) {
            return s;
        }
        bool p[n][n];
        int start = 0;
        int mL = 1;
        memset(p, 0, sizeof(p));
        
        for(int i=0; i<n; ++i)
            p[i][i] = true;
        
        for(int i=0; i<n-1; ++i) {
            if(s[i] == s[i+1]) {
                start = i;
                mL = 2;
                p[i][i+1] = true;
            }
        }
        
        for(int k=3; k<=n; ++k) {
            for(int i=0; i<n-k+1; ++i) {
                int j = i+k-1;
                if(p[i+1][j-1] && s[i] == s[j]) {
                    p[i][j] = true;
                    if(k>mL) {
                        mL = k;
                        start = i;
                    }
                }
            }
        }
        
        string res;
        for(int i=start; i<=start+mL-1; i++) {
            res.push_back(s[i]);
        }
        return res;
    }
};