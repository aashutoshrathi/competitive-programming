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
        ll n, k;
        cin >> n >> k;
        if(n <= k) {
            cout << "Arpa" << endl;
        } else {
            if(n%(k+1) == 0) {
                cout << "Dishant" << endl;
            } else {
                cout << "Arpa" << endl;
            }
        }
    }
    return 0;
}

// till k -> Arpa
// k+1 -> D
// k+2 -> A
// k+3 -> A
// 2*k-1 -> A
// 2k -> A
// 2k + 1 -> A
// 2k + 2 -> D
// 2k + 3 -> A
// 3k -> A
// 3k+1 -> A
// 6 2 -> D
// 7 2 -> A