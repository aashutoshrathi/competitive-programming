class Solution {
public:
    int basicStuff(vector<int>& A, int f = 1) {
        int csum = A[0]*f;
        int sum = csum;
        for(int i=1; i<A.size(); i++) {
            csum = max(A[i]*f, csum+A[i]*f);
            sum = max(csum, sum);
        }
        return sum;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int maxWa = *max_element(A.begin(), A.end());
        // jab sabse bada hi 0 se chota ho
        if(maxWa < 0) {
            return maxWa;
        }
        
        // Normal Kadane stuff
        int easyOne = basicStuff(A);
        // Sum(A) + Kadane(-A) [Maximum decreasing subarray];
        int toughOne = basicStuff(A, -1) + accumulate(A.begin(), A.end(), 0);
        return max(easyOne, toughOne);
    }
};