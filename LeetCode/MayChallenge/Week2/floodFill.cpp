class Solution {
public:
    int n, m;
    void karta(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& v) {
        if(image[sr][sc] == newColor)
            return;
        v[sr][sc] = 1;
        if(sr-1 >= 0 && !v[sr-1][sc] && image[sr-1][sc] == image[sr][sc]) {
            karta(image, sr-1, sc, newColor, v);
        }
        if(sr+1 < n && !v[sr+1][sc] && image[sr+1][sc] == image[sr][sc]) {
            karta(image, sr+1, sc, newColor, v);
        }
        if(sc-1 >= 0 && !v[sr][sc-1] && image[sr][sc-1] == image[sr][sc]) {
            karta(image, sr, sc-1, newColor, v);
        }
        if(sc+1 < m && !v[sr][sc+1] && image[sr][sc+1] == image[sr][sc]) {
            karta(image, sr, sc+1, newColor, v);
        }
        image[sr][sc] = newColor;
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        vector<vector<bool>> ghoomiGhoomi(n, vector<bool> (m, 0));
        if(image[sr][sc] != newColor) {
            karta(image, sr, sc, newColor, ghoomiGhoomi);
        }
        return image;
    }
};