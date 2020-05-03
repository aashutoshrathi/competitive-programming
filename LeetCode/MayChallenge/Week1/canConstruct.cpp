class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(char i: magazine) {
            m[i]++;
        }
        
        for(char i: ransomNote) {
            if(m[i] > 0) {
                m[i]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
