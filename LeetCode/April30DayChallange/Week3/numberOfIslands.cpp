class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size(), y = 0, numIslands = 0;
        if(x) y = grid[0].size();
        
        // iterate through grid 
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(grid[i][j] == '1'){
                    numIslands++;
                    
                    // bfs
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    
                    while(!q.empty()){
                        pair<int,int> top = q.front();
                        q.pop();
                        int a = top.first; int b = top.second;
                        
                        if( a < 0 or b < 0 or a >= x or b >= y or grid[a][b] != '1') continue;
                        else{
                            grid[a][b] = '0';
                            int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                            for(int i = 0; i < 4; i++)  
                                q.push(make_pair(a + changeX[i], b + changeY[i]));
                        }
                    }
                    
                    
                }
            }
        }
        return numIslands;
    }
};