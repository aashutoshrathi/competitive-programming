class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> s;
        for(auto i: J) {
            s.insert(i);
        }
        int res = 0;
        for(auto i: S) {
            if(s.find(i) != s.end()) {
                res++;
            }
        }
        return res;
    }
};