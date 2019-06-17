// https://www.interviewbit.com/problems/maximum-absolute-difference/
// 

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

int maxArr(vector<int> &A) {
    vector<int> B(A.size()), C(A.size());
    for(int i=0; i<A.size(); i++) {
        B[i]=A[i]+i;
        C[i]=A[i]-i;
    }
    int cDist = *max_element(C.begin(),C.end())-*min_element(C.begin(),C.end());
    int bDist = *max_element(B.begin(),B.end())-*min_element(B.begin(),B.end());
    return max(cDist, bDist);
}
