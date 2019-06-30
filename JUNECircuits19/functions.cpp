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
typedef long long ll;

ll gcd(ll a,ll b){
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)  { 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

ll modInverse(ll a, ll m) { 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return; 
    else
        return (x%m + m) % m;
}

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
	if (a == 0)
		return make_tuple(b, 0, 1);

	ll gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


// f(2n) + f(2n+1) + f(2n+2) = 3^(n+1) + 2

ll getOddSum(ll a, ll n, ll p) {
    
}

int main() {
    fast
    ll t, p;
    cin >> t >> p;
    while(t--) {    
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        cout << res%p << endl;
    }
    return 0;
}