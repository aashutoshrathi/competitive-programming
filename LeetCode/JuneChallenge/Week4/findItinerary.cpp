class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m; // multiset orders itself
        for(auto i: tickets) {
            m[i[0]].insert(i[1]);
        }
        
        vector<string> res;
        
        stack<string> tracker;
        tracker.push("JFK");
        
        while(!tracker.empty()) {
            string top = tracker.top();
            if(!m[top].size()) {
                res.push_back(top);
                tracker.pop();
            } else {
                auto first = m[top].begin();
                tracker.push(*first);
                m[top].erase(first);
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
