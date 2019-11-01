// https://leetcode.com/problems/most-common-word/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        string s = "";
        for(auto &i: paragraph) {
            i = tolower(i);
            if('a' <= i and i <= 'z') {
                s.push_back(i);
            } else {
                if(!s.empty()) {
                    ++m[s];
                    s = "";
                }
            }
        }

        // Important when banned array is empty        
        if(!s.empty()) {
            ++m[s];
            s = "";
        }
        
        for(auto &i: banned)
            m[i] = 0;
        
        string res= (*(m.begin())).first;
        for(auto &i: m) {
            if(i.second > m[res]) {
                res = i.first;
            }
        }
        return res;
    }
};