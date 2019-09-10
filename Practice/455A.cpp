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
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> a(LIM);
    map<ll, ll> m;
    fi(n) {
        cin >> v[i];
        m[v[i]]++;
    }
    sort(v.begin(), v.end());
    a[0] = 0;
    a[1] = m[1];

    for(ll i=2; i<LIM; i++) {
        a[i] = max(a[i-1], a[i-2]+m[i]*i);
    }

    cout << a[LIM-1] << endl;
    return 0;
}