// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcountll(z) to get set bit count of z
// Don't use endl use '\n'
// Life is not looney toons, jitna pyaara din h
// utne pyaare hum, esa kese?

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
        ll x, y, l, r, z;
        cin >> x >> y >> l >> r;
        // is condition ne 4 baar WA dilwaye
        // Maaro mujhe!! Mujhe Maaro!
        if(x == 0 || y == 0) {
            cout << l << endl;
        } else {
            // subtask 1
            if(r >= 2*max(x, y)) {
                z = x|y;
            }

            // subtask 2 and beyond
            else {
                if(l == r) {
                    z = r;
                } else {
                    ll maxwa = INT_MIN;
                    for(ll i=l; i<=r; i++) {
                        ll res = (x&i)*(y&i);
                        if(res > maxwa) {
                            // cout << res << ": " << i << endl;
                            maxwa = res;
                            z = i;
                        }
                    }
                }
            }
            cout << z << endl;
        }
    }
    return 0;
}