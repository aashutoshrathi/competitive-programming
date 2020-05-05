class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> x;
        int res = -1;
        for(char i: s) {
            x[i]++;
        }
        
        for(int i=0; i<s.size(); i++) {
            if(x[s[i]] == 1) {
                res = i;
                break;
            }
        }
        
        return res;
    }
};