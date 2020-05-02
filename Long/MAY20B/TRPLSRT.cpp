// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
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
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;
#define endl "\n"

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll p[n];
        vector<ll> res;
        fi(n) {
            cin >> p[i];
            if(p[i] != i+1) {
                res.push_back(p[i]);
            }
        }
        int m = res.size();
        if(m/3 > k) {
            cout << -1;
        } else {
            cout << m/3 << endl;
            sort(res.begin(), res.end());
            for(int i=0; i<res.size(); i+=3) {
                cout << res[i] << " " << res[i+1] << " " << res[i+2];
            }
        }
    }
    return 0;
}