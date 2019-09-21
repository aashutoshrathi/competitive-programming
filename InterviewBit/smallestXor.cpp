// Since sorted adj pairs have min xor
// https://www.interviewbit.com/problems/min-xor-value/

int findMinXor(vector<int> &A) {
    int res = INT_MAX;
    sort(A.begin(), A.end());
    for(int i=0; i<A.size()-1; i++) {
        res = min(res, A[i]^A[i+1]);
    }
    return res;
}
