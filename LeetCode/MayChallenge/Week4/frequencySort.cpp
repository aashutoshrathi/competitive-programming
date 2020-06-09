class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        map<char, int> m;
        for(char i: s)
            m[i]++;
        
        auto cmp = [](const auto &p1, const auto &p2) {
            return p2.second < p1.second || !(p1.second < p2.second) && p1.first < p2.first;
        };
        
        set <pair<char, int>, decltype( cmp )> st(m.begin(), m.end(), cmp);
        
        for(auto i: st) {
            for(int j=0; j<i.second; j++) {
                res += i.first;
            }
        }
        return res;
    }
};

