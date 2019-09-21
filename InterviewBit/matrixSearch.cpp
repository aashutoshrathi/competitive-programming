int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = A[0].size();
    int Rl=0, Rr=m-1, Rmid;
    int row = Rl;
    while(Rl<=Rr) {
        Rmid = Rl + (Rr-Rl)/2;
        if(A[Rmid][0] == B) {
            return 1;
        }
        if(A[Rmid][0] > B) {
            Rr = Rmid - 1;
        }
        else {
            row = Rmid;
            Rl = Rmid + 1;
        }
    }
    
    int cl = 0, cr = n-1, cmid;
    
    while(cl <= cr) {
        cmid = cl + (cr-cl)/2;
        if(A[row][cmid] == B) {
            return 1;
        }
        if(A[row][cmid] > B) {
            cr = cmid - 1;
        } else {
            cl = cmid + 1;
        }
    }
    
    return 0;
    
}
