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
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    long double res = a[0];
    for(ll i=1; i<n; i++) {
        res = (res+a[i])/2.0;
    }
    cout << res << endl;
    return 0;
}
