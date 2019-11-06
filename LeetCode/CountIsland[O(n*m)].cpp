// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<vector<bool>> vis;
    int ROW, COL;
    
    bool isOk(vector<vector<char>>& grid, int i, int j) {
        return (i >= 0 && i < ROW && j >=0 && j< COL && (grid[i][j] == '1') && !vis[i][j]);
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j) {
        vis[i][j] = 1;
        
        if(isOk(grid, i-1, j)) {
            DFS(grid, i-1, j);
        }
        if(isOk(grid, i+1, j)) {
            DFS(grid, i+1, j);
        }
        if(isOk(grid, i, j+1)) {
            DFS(grid, i, j+1);
        }
        if(isOk(grid, i, j-1)) {
            DFS(grid, i, j-1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        ROW = grid.size();
        
        if(ROW == 0) {
            return 0;
        }
        COL = grid[0].size();
        
        vector<bool> x(COL, 0);
        for(int i=0; i<ROW; i++) {
            vis.push_back(x);
        }
        
        int count = 0;
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                if((grid[i][j] == '1') && !vis[i][j]) {
                    DFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};