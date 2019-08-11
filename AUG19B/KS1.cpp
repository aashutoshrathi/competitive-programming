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

// void preprocess(ll arr[], ll n, vector<vector<ll> >& cnt) {
//     ll i, j; 
//     for (i = 0; i < 32; i++) { 
//         cnt[i][0] = 0; 
//         for (j = 0; j < n; j++) { 
//             if (j > 0) { 
//                 cnt[i][j] = cnt[i][j - 1]; 
//             }
//             if (arr[j] & (1 << i)) 
//                 cnt[i][j]++; 
//         }
//     } 
// }

// ll findXOR(ll L, ll R, const vector<vector<ll> > cnt) {
//     ll ans = 0, noOfOnes, i; 
//     for (i = 0; i < 32; i++) { 
//         noOfOnes = cnt[i][R] - ((L > 0) ? cnt[i][L - 1] : 0); 
//         if (noOfOnes & 1) { 
//             ans += (1 << i); 
//         } 
//     }
//     return ans;
// }

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n];

        for(ll i=0; i<n; i++) {
            cin >> a[i];
        }

        ll res = 0;
        for(ll i=0; i<n-1; i++) {
            ll xorwa = a[i];
            for(ll j=i+1; j<n; j++) {
                xorwa ^= a[j];
                // cout << xorwa << endl;
                if(xorwa == 0) {
                    res += (j-i);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
