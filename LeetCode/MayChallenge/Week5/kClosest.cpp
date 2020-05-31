class Solution {
public:
    struct CompareDistance { 
        bool operator()(vector<int> const& p1, vector<int> const& p2) { 
            int p1Distance = p1[0]*p1[0] + p1[1]*p1[1];
            int p2Distance = p2[0]*p2[0] + p2[1]*p2[1];
            return p1Distance > p2Distance; 
        } 
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, CompareDistance> Q;
        vector<vector<int>> res;
        for(auto point: points)
            Q.push(point);
  
        while (!Q.empty() && k--) { 
            res.push_back(Q.top()); 
            Q.pop();
        } 
        return res;
    }
};

