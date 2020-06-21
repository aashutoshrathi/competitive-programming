#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    void visit(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] == 'O') {
            board[x][y] = 'V';

            if(x+1 < m)
                visit(board, x+1, y);
            if(y+1 < n)
                visit(board, x, y+1);
            if(y > 1)
                visit(board, x, y-1);
            if(x > 1)
                visit(board, x-1, y);
        }
    }

    void surroundedAreas(vector<vector<char>>& board) {
        m = board.size();
        if(!m)
            return;
        n = board[0].size();

        // Mark all connected with boundary Os
        for(int i=0; i<m; i++) {
            visit(board, i, 0);
            visit(board, i, n-1);
        }

        for(int i=0; i<n; i++) {
            visit(board, 0, i);
            visit(board, m-1, i);
        }

        for(int i=0; i<m; i++)
            for(int j=0; j < n; j++)
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
        
    }
};