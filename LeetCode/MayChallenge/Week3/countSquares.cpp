class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int res = 0;
        // Classical DP Approach
        // Learned a lot while implementing this
        for(int i=0; i<m.size(); i++) {
            for(int j=0; j<m[0].size(); j++) {
                if(i && j && m[i][j])
                    m[i][j] += min({m[i-1][j], m[i][j-1], m[i-1][j-1]});
                res += m[i][j];
            }
        }
        return res;
    }
};

