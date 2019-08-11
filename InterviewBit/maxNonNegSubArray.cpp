
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std; // Kyuki yahi mai-baap hai

using ll = long long;

vector<int> maxset(vector<int> &A) {
    ll n = A.size();
    ll x=0, y=0, s=0, mx=0, my=0, ms=0;
    for(ll i=0;i<n;i++){
        if(A[i]<0) x=i+1, y=i+1, s=0;
        else {
            s+=A[i], y++;
            if(s>ms || ms>=s && mx==x)
                ms=s, mx=x, my=y;
        }
    }
    vector<int> V(A.begin()+mx, A.begin()+my);
    return V;
}