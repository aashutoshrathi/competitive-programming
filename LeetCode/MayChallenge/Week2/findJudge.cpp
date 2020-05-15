class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>trustedBy(N+1, 0);
        vector<int>trusted(N+1, 0);
        for(auto i: trust) {
            trustedBy[i[0]]++;
            trusted[i[1]]++;
        }
        int candidate = -1;
        for(int i=1; i<=N; i++) {
            if(trusted[i] == N-1 && trustedBy[i] == 0) {
                candidate = i;
                break;
            }
        }
        
        return candidate;
    }
};