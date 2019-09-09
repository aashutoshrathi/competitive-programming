// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define fj(a) for (ll j = 0; j < a; ++j)
#define fi(a) for (ll i = 0; i < a; ++i)
#define mod(x) 			x%1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef unsigned long long ll;

ll nCr(ll n, ll r) {
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;

    for (ll i = 1; i <= n; i++) { 
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1]); 
    } 
    return C[r]; 
}

ll solve(ll n, ll k) {
    ll a[n];
    fi(n)
        cin >> a[i];
    sort(a, a+n);
    ll ca = 0, cb = 0;

    fi(n) {
        if(i < k) {
            if(a[i] == a[k-1])
                ca++;
        }
        if(a[i] == a[k-1])
            cb++;
    }
    
    ll count = nCr(cb, ca);
        
    return count;
}

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}