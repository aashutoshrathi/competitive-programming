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

ll gcdList(ll arr[]) {
    ll res = arr[0];
    for(int i=1; i<4; i++) {
        res = gcd(res, arr[i]);
    }
    return res;
}

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
	if (a == 0)
		return make_tuple(b, 0, 1);

	ll gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        ll result = 0;
        cin >> n;
        if(n < 4) {
            cout << 0 << endl;
        } else {
            if(n == 4) {
                cout << 1 << endl;
            } else {
                for(ll i = 1; i <= n/2; i++) {
                    
                }
            }
        }
    }
    return 0;
}