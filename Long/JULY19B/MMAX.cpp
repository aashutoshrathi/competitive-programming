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
        ll n;
        string k;
        cin >> n;
        cin >> k;
        ll res = 0;
        for (ll i = 0; i < k.length(); i++)
            res = (res*10 + (ll)k[i] - '0') % n;
        if(res > (n+1)/2) {
            res = n - res;
        }
        cout << MIN(2*res - ((n%2==0) && (res==n/2)), 2*(n/2)) << endl;
    }
    return 0;
}