class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> DP(m+1,vector<int>(n+1));
        for(int i=1; i<=m; i++) {
            for(auto j=1; j<=n; j++) {
                if(A[i-1] == B[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                } else {
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                }
            }
        }
        return DP[m][n];
    }
};

