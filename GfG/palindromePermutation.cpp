#include <bits/stdc++.h>
using namespace std;

bool canFormPalindrome(string s) { 
    unordered_map<char, int> m;

    for (int i = 0; s[i];  i++) {   
        if(s[i] >= 'a' && s[i] <= 'z')
            m[s[i]]++;
    }

    int odd = 0;
    for (auto i: m) { 
        if (i.second & 1) 
            odd++;
        if (odd > 1) 
            return false;
    }
    return true;
} 
