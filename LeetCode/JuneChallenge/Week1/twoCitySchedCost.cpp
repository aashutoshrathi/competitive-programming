class Solution {
public:
    static bool compare(const pair<int, int>&i, const pair<int, int>&j) {
        return i.second < j.second;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> diff;
        int total = 0;
        int n = costs.size();
        for(int i=0; i<n; i++)
            diff.push_back({i, costs[i][0] - costs[i][1]});
        
        sort(diff.begin(), diff.end(), compare);
        
        for(int i=0; i<n/2; i++) {
            int idxA = diff[i].first;
            int idxB = diff[n-i-1].first;
            // cout << idxA << " " << idxB << endl;
            total += costs[idxA][0];   
            total += costs[idxB][1];   
        }
        return total;
    }
};

