// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
// Don't use endl use '\n'
// To make pair use {a, b}

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
typedef unsigned long long ull;
#define endl "\n"
// Use more random comments to keep unique
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

template<typename T>
void pop_front(std::vector<T>& vec) {
    assert(!vec.empty());
    vec.erase(vec.begin());
}

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll h[n], iq[n];
        fi(n)
            cin >> h[i];
        fi(n)
            cin >> iq[i];
        
        vector<ll> res(n, 1);

        for(int i=1; i<n; i++) {
            for (int j=0; j<i; j++)   
                if (h[i] > h[j] && iq[i] < iq[j])  
                    res[i] = max(res[i], res[j]+1);
        }
        sort(res.begin(), res.end());
        cout << res[n-1] << endl;
    }
    return 0;
}