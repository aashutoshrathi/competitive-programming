class Trie {
public:
    Trie* children[26];
    bool end;
    
    Trie(): end(false) {
        for(int i=0; i<26; i++)
            children[i] = nullptr;
    }
    
    void insertList(vector<string>& words) {
        for(string word: words) {
            Trie* root = this;
            for(char c: word) {
                int index = c-'a';
                if(!root->children[index])
                    root->children[index] = new Trie();
                root = root->children[index];
            }
            root->end = true;
        }
    }
};

class Solution {
public:
    void lookAround(Trie* dict, int i, int j, vector<vector<char>>& board, vector<string>& result, string cursor) {
        char curr = board[i][j];
        if(curr == '*')
            return;
        board[i][j] = '*';
        Trie* trie = dict->children[curr-'a'];
        if(trie) {
            string newCursor = cursor + curr;
            if(trie->end && find(result.begin(), result.end(), newCursor) == result.end())
                result.push_back(newCursor);
            if(i < board.size() - 1)
                lookAround(trie, i+1, j, board, result, newCursor);
            if(j < board[0].size() - 1)
                lookAround(trie, i, j+1, board, result, newCursor);
            if(i)
                lookAround(trie, i-1, j, board, result, newCursor);
            if(j)
                lookAround(trie, i, j-1, board, result, newCursor);
        }
        
        board[i][j] = curr;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        
        Trie dict;
        dict.insertList(words);
        
        vector<string> result;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                lookAround(&dict, i, j, board, result, "");
    
        return result;
    }
};
