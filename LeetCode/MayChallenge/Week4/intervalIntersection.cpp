class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i=0, j=0;
        vector<vector<int>> res;
        while(i<A.size() && j<B.size()) {
            vector<int> temp = { max(A[i][0], B[j][0]), min(A[i][1], B[j][1]) };
            
            if(A[i][0] > B[j][1]) {
                j++;
                continue;
            } else if(B[j][0] > A[i][1]) {
                i++;
                continue;
            }
            
            if(A[i][1] <= B[j][1]) {
                i++;
            } else {
                j++;
            }
            
            res.push_back(temp);
        }
        return res;
    }
};

