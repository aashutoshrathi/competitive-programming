// https://www.interviewbit.com/problems/maxspprod
// 

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

int maxSpecialProduct(vector<int> &A) {
    long long int n = A.size();
    long long int B[n],C[n];
    int max = 0;
    for(int i =0;i<n;i++) B[i] = 0;
    for(int i =0;i<n;i++) C[i] = 0;
    
    for(int i =1;i<n;i++) {
        for(int j = i-1;j >= 0;j--) {
            if(A[j] > A[i]) {
                B[i] = j;
                break;
            }
        }

        for(int j = i+1;j < n;j++) {
            if(A[j] > A[i]) { 
                C[i] = j;
                break;
            }
        }
        B[i] = B[i]*C[i];
        if(B[i] > max) max = B[i];
    
    }
    return max%1000000007;
}
