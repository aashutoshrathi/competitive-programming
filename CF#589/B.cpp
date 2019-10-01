// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
// Don't use endl use '\n'

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fi(a) for (ll i = 0; i < a; ++i)
#define fj(a) for (ll j = 0; j < a; ++j)
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;
#define endl "\n"

const ll MOD = 1e9+7;

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

int main() {
    tezzzzz
    int h, w;
    cin >> h >> w;
    ll r[h], c[w];
    fi(h)
        cin >> r[i];
    fi(w)
        cin >> c[i];

    ll cnt = 0;
    for(int i=0; i<h; i++) {
        ll rc = 0;
        for(int j=0; j<w; j++) {
            if(j>r[i] && i>c[j]) {
                cnt++;
                // cout << i << " " << j << endl;
            }
            else if((i < c[j]) ^ (j < r[i])) {
                cout << 0 << " " << i << " " << j << endl;
                return 0;
            }
        }
    }

    ll res;
    if(cnt == 0) {
        res = 0;
    } else{
        res = power(2, cnt, MOD);
    }
    // cout << cnt << endl;
    cout << res << endl;
    
    return 0;
}
