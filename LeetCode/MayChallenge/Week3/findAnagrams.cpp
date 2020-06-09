#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool countMatches(int x[], int y[]) {
        for(int i=0; i<26; i++) {
            if(x[i] != y[i])
                return false;
        }
        return true;
    }
    
    int f(char x) {
        return x-'a';
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int a = s.size();
        int b = p.size();
        
        if(a < b) return res;
        
        int pCount[26] = {0};
        int wCount[26] = {0};
        
        for(int i=0; i<b; i++) {
            pCount[f(p[i])]++;
            wCount[f(s[i])]++;
        }
        
        for(int i=b; i<a; i++) {
            if(countMatches(pCount, wCount)) {
                res.push_back(i-b);
            }
            wCount[f(s[i])]++; // add new one
            wCount[f(s[i-b])]--; // remove old one
        }
        
        // Ahh missed this n times.
        if(countMatches(pCount, wCount)) {
            res.push_back(a-b);
        }
        return res;
    }
};