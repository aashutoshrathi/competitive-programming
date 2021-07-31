// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
// assignment ka return val is RHS
 
#include <bits/stdc++.h> // Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;
// Kyuki yahi mai-baap hai
 
#define mod(x)          x%1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;

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

unordered_map<ll, ll> m;

ll breakDown(ll x) {
    if (m.find(x) != m.end()) {
        return m[x];
    }
    if (x < 12) return x;
    ll broken = breakDown(x/2) + breakDown(x/3) + breakDown(x/4);
    return m[x] = max(x, broken);
}

int main() {
    fast;
    ll n;
    while(cin >> n) {
        cout << breakDown(n) << endl;
    }
    return 0;
}
