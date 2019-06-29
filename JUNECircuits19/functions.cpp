// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
 
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
typedef unsigned long long ll;

ll gcd(ll a,ll b){
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
	if (a == 0)
		return make_tuple(b, 0, 1);

	ll gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

ll power(ll x, ll y, ll p) { 
    ll res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
}


// f(2n) + f(2n+1) + f(2n+2) = 3^(n+1) + 2

ll f(ll n, ll p) {
    if(n%2 == 1) {
        return power(3, n/2, p);
    } else {
        return power(3, n/2 +1, p) - power(3, n/2, p) + 2;
    }
}

int main() {
    fast
    ll t, p;
    cin >> t >> p;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        for(ll i=l; i<=r; i++) {
            cout << i << ":" << f(i,p) << endl;
            res = (res + f(i, p))%p;
        }
        cout << res%p << endl;
    }
    return 0;
}