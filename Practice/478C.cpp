// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fj(a) for (ll j = 0; j < a; ++j)
#define fi(a) for (ll i = 0; i < a; ++i)
#define fiz(a) for (ll i = 1; i <= a; ++i)
#define mod(x) 			x%1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
#define LIM 200010LL
typedef pair <long, long> lpairs;
typedef long long ll;

int main() {
    tezzzzz
    ll a[3];
    fi(3)
        cin >> a[i];
    
    ll ans = min(a[0], min(a[1], a[2]));

    fi(3)
        a[i] -= ans;

    vector<ll> lT;
    fi(3)
        if(a[i] > 0) lT.pb(a[i]);
    
    if(lT.size() < 2) {
        cout << ans << endl;
        return 0;
    } else {
        while((lT[0] >= 1 && lT[1] > 1) || (lT[1] >= 1 && lT[0] > 1)) {
            if(lT[0] >= lT[1]) {
                int bal = min(lT[0]/2, lT[1]);
                lT[0] -= 2*bal;
                lT[1] -= bal;
                ans++;
            } else {
                int bal = min(lT[1]/2, lT[0]);
                lT[0] -= bal;
                lT[1] -= 2*bal;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}