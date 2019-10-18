// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fi(a) for (ll i = 0; i < a; ++i)
#define mod(x) 			x%1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n], x;
        ll jod = 0;
        if(n == 1) {
            cin >> x;
            cout << x << endl;
        } else {
            vector<ll> bade;
            fi(n) {
                cin >> a[i];
                if(a[i] > k) {
                    bade.push_back(a[i]);
                }
                else {
                    jod += a[i];
                }
            }

            ll z = bade.size();
            sort(bade.begin(), bade.end());

            for(int i=0; i<z-1; i++) {
                if(bade[i] > k) {
                    int val = bade[i]-k;
                    bade[i] -= val;
                    bade[i+1] -= val;
                }
            }

            for(auto i: bade) {
                jod += i;
            }

            cout << jod << endl;
        }
    }
    return 0;
}
