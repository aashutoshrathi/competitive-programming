typedef pair<int, int> ipairs;

class Solution {
public:
    static bool compare(ipairs p, ipairs q) {
        return p.second == q.second ? p.first > q.first : p.second > q.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i: nums)
            m[i]++;
        
        vector<ipairs> count_arr(m.begin(), m.end()); 
        
        sort(count_arr.begin(), count_arr.end(), compare);
 
        for (int i=0; i<k; i++)
            res.push_back(count_arr[i].first);
        
        return res;
    }
};
