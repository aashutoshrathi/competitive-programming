// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

 
#define mod(x) 			x%1000000007;
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
        ll q;
        cin >> q;
        ll x;
        int a[2000005]={0};
        vector<ll> v;
        ll o = 0, e = 0;
        for(ll i=0; i<q; i++) {
            cin >> x;
            ll l=v.size();
            if(a[x]==0) {
                for(ll j=0; j<l; j++) {
                    ll z = x^v[j];
                    if(a[z]==0) {
                        v.push_back(z);
                        a[z]=1;
                        __builtin_popcount(z)%2 ? o++ : e++;
                    }
                }
                v.push_back(x);
                a[x]=1;
                __builtin_popcount(x)%2 ? o++ : e++;
            }

            // Set
            // for(ll j=0; j<v.size(); j++) {
            //     cout << v[j] << " ";
            // } cout << endl;

            // for(ll j=0; j<v.size(); j++) {
            //     parity(v[j]) ? o++ : e++;
            // }
            cout << e << " " << o << endl;
        }
    }
    return 0;
}