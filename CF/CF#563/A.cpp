// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
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
#define fcout(a, n) \
for(ll i = 0; i < n; i++) \
    printf("%lld ", a[i]); \
    printf("\n");


int main() {
    fast
    ll n;
    cin >> n;
    ll m = 2*n;
    ll a[m];
    ll sum = 0;
    for (ll i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum%2 == 1) {
        fcout(a, m);
    } else {
        sort(a, a+m);
        ll ssum = 0;
        for (ll i = 0; i < n; i++) {
            ssum += a[i];
        }
        if(ssum == sum/2) {
            cout << -1 << endl;
        } else {
            fcout(a, m);
        }
    }
    return 0;
}