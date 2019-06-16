#include <bits/stdc++.h> 
#include <stdio.h>
using namespace std;

// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
// Asked in:  
// Facebook
// Paypal
// Yahoo
// Microsoft
// LinkedIn
// Amazon
// Goldman Sachs


// Paradigm: Dynamic Programming
int maxSubArray(const vector<int> &A) {
    int maxA = A[0]; 
    int cMax = A[0];
  
   for (int i = 1; i < A.size(); i++) { 
        cMax = max(A[i], cMax+A[i]); 
        maxA = max(maxA, cMax); 
   } 
   return maxA;
}
