// April 6

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    vector<int> c(26, 0);
    for(int i=0; i<strs.size(); i++) {
        std::fill(c.begin(), c.end(), 0);
        for(int j=0; j<strs[i].size(); j++) {
            c[strs[i][j]-'a']++;
        }
        
        string s;
        for (auto x: c)
            s += "@" + to_string(x);
        
        m[s].push_back(strs[i]);
    }
    vector<vector<string>> res;
    for(auto i: m) {
        res.push_back(i.second);
    }
    return res;
}