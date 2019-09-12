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
const long long int MOD = 1e9+7;

ll power(ll x, ll y, ll p) { 
    ll res = 1;
  
    x = x % p;
  
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}
  
ll modInverse(ll n, ll p) { 
    return power(n, p-2, p); 
}

ll ncR(ll n, ll r, ll p) { 
   if (r==0) 
      return 1; 

    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
}

ll solve(ll n, ll k) {
    ll a[n];
    unordered_map<ll, ll> m;
    fi(n) {
        cin >> a[i];
        m[a[i]]++;
    }
    ll res = 1+n; // subs with len 0 and len 1
    ll sub = 0;
    for(ll i=2; i<=k; i++) {
        res += ncR(n, i, MOD);
        for(auto x = m.begin(); x != m.end(); x++) {
            if(i >= x->second && x->second > 1) {
                sub += ncR(i, x->second, MOD);
            }
            // cout << "X-sec " << x->second << endl;
        }
    }
    // cout << res << " "  << sub << endl;
    res -= sub;
    return res%MOD;
}

int main() {
    tezzzzz
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}