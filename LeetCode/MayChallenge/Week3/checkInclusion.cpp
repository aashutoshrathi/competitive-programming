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
    
    bool checkInclusion(string s1, string s2) {
        int a = s1.size();
        int b = s2.size();
        if(b < a) {
            return false;
        }
        int cnt[26] = {0};
        int cntTwo[26] = {0};
        
        for(int i=0; i<a; i++) {
            cnt[f(s1[i])]++;
            cntTwo[f(s2[i])]++;
        }
        
        for(int i=a; i<b; i++) {
            if(countMatches(cnt, cntTwo)) {
                return true;
            }
            cntTwo[f(s2[i])]++;
            cntTwo[f(s2[i-a])]--;
        }
        
        if(countMatches(cnt, cntTwo)) {
            return true;
        }
        
        return false;
    }
};
