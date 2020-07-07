class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    res += (!i) + (i == m - 1);
                    res += (!j) + (j == n - 1);
                    
                    if(i) res += !grid[i-1][j];
                    if(j) res += !grid[i][j-1];
                    if(i < m - 1) res += !grid[i+1][j];
                    if(j < n - 1) res += !grid[i][j+1];   
                }
            }
        }
        return res;
    }
};