#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int res = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) q.push({i, j});
            }
        }

        while(!q.empty()) {
            int size = q.size();
            res++;
            for(int i=0; i<size; i++) {
                for(int j=0; j<4; j++) {
                    int x = q.front().first + dx[j];
                    int y = q.front().second + dy[j];
                    if(x>=0 && x<n && y>=0 && y<n && !grid[x][y] && !vis[x][y]) {
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
                q.pop();
            }
        }
        return res == 1 ? -1 : res - 1;
    }
};
// @lc code=end

