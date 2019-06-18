// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Asked in Amazon (Took me 34 minutes to fix all types and stuff)

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

vector<int> repeatedNumber(const vector<int> &A) {
    unsigned long long sum = 0;
    unsigned long ssum = 0;
    long long int n = A.size();
    for(long long i=0; i<n; i++) {
        long long x = (long long)A[i];
        sum += x;
        ssum += x*x;
    }
    long long diff = (n*n+n)/2 - sum; // b-a
    long long diffS = n*(n+1)*(2*n+1)/6 - ssum; // (b-a)*(b+a)
    unsigned long long bPa = diffS/diff;
    vector<int> v;
    v.push_back((bPa-diff)/2);
    v.push_back((bPa+diff)/2);
    return v;
}
