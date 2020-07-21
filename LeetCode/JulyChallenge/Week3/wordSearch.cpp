class Solution {
public:
    bool search(vector<vector<char>>& board, int idx, int i, int j, string word) {
        char curr = board[i][j];

        if(idx == word.size())
            return true;
        
        bool res = false;
        if(curr == '*')
            return res;
        // mark as processing
        board[i][j] = '*';

        if(i && board[i-1][j] == word[idx] && search(board, idx+1, i-1, j, word))
            res = res || true;
        else if(j && board[i][j-1] == word[idx] && search(board, idx+1, i, j-1, word))
            res = res || true;
        else if(j < board[0].size()-1 && board[i][j+1] == word[idx] && search(board, idx+1, i, j+1, word))
            res = res || true;
        else if(i < board.size()-1 && board[i+1][j] == word[idx] && search(board, idx+1, i+1, j, word))
            res = res || true;
        
        board[i][j] = curr; // reset the char
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == word[0] && search(board, 1, i, j, word))
                    return true;
        return false;
    }
};
