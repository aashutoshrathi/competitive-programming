// https://leetcode.com/problems/most-common-word/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banset;
        for(auto i: banned) {
            banset.insert(i);
        }
        
        unordered_map<string, int> m;
        
        
        for (int i = 0, len = paragraph.size(); i < len; i++) {
            if (ispunct(paragraph[i])) {
                paragraph[i] = ' ';
            }
            else if(isupper(paragraph[i])) {
                paragraph[i] += ('z'-'Z');
            }
        }
        
        istringstream iss(paragraph);
        vector<string> results((istream_iterator<string>(iss)),
                                 istream_iterator<string>());
        
        for(auto i: results) {
            if(banset.find(i) == banset.end())
                m[i]++;
        }

        
        string res = "";
        int mx = 0;
        for(auto i: m) {
            if(i.second > mx) {
                mx = i.second;
                res = i.first;
            }
        }
        return res;
    }
};