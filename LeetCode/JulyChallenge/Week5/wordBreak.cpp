class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> dp;
    
    void wordBuilder(int k, string s) {
        vector<string> temp;   
        for(int i = 0; i <= s.size() - k; i++) {
            string target = s.substr(k, i);
            if(dict.count(target)) {
                string first = target;      
                
                if(k + i == s.size())
                    temp.push_back(first);
                
                else {
                    if(!dp.count(k + i))
                        wordBuilder(k + i, s);
                    for(auto j : dp[k + i])
                        temp.push_back(first + " " + j);
                }
            }
        }
        
        dp[k] = temp;
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {   
        for(string i: wordDict)
            dict.insert(i);
        
        wordBuilder(0, s);
        return dp[0]; 
    }

};
