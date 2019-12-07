// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
// Don't use endl use '\n'

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fi(a) for (ll i = 0; i < a; ++i)
#define fj(a) for (ll j = 0; j < a; ++j)
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;
#define endl "\n"

const ll MOD = 1e9+7;

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
  
ll modInverse(ll n, ll p) { 
    return power(n, p-2, p); 
}

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
	if (a == 0)
		return make_tuple(b, 0, 1);

	ll gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

ll gcd(ll a, ll b) {
    if(a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

vector<int> primes;

void SieveOfEratosthenes(int n) {
    primes.clear();
    bool prime[n+1];
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) {
       if (prime[p]) {
           primes.push_back(p);
       }
    } 
}

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll temp = n;
        ll j = 1;
        string trep = "";
        while(temp > 0) {
            char x = ('0'+ temp%3);
            trep = x + trep;
            temp/=3;
        }
        cout << "rep:" << trep << endl;
        vector<int> z;
        vector<int> two;
        for(int i=0; i<trep.size(); i++) {
            if(trep[i] == '2') {
                two.push_back(i);
            }
            if(trep[i] == '0') {
                z.push_back(i);
            }
        }
        // if(z.size())
        //     cout << "Z: ";
        // for(auto i: z)
        //     cout << i << " ";
        // if(z.size())
        //     cout << endl;
        
        // if(two.size())
        //     cout << "Two: ";
        // for(auto i: two)
        //     cout << i << " ";
        // if(two.size())
        //     cout << endl;


        if(z.size() && two.size() && two[0] > z[z.size()-1] && z.size() == two.size()) {
            for(int i=0; i<z.size(); i++) {
                n += pow(3, z[i]);
                n -= pow(3, two[i]);
            }
        }

        else if(z.size() != two.size() || (z.size() && two.size() && two[0] < z[z.size()-1])) {
            n = pow(3, trep.size());
        }

        cout << n << endl;
    }
    return 0;
}
