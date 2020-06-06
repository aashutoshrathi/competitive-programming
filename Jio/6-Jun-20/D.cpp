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
#define ERR 0.001

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

double eqn(double a, double b, double c, double x) {
    return x*x*x + a*x*x + b*x + c;
}

double primeEqn(double a, double b, double x) {
    return 3*x*x + 2*a*x + b;
}

int main() {
    tezzzzz
    int t;
    cin >> t;
    while(t--) {
        ll n, u;
        cin >> n >> u;
        ll v[n];
        ll sum_v_cube = 0;
        ll sum_v = 0;
        ll sum_v_sq = 0;
        fi(n) {
            cin >> v[i];
            sum_v += v[i];
            sum_v_sq += v[i]*v[i];
            sum_v_cube += v[i]*v[i]*v[i];
        }
        // So it will form a cubic starting with nt^3 types
        double constant = double(sum_v_cube - u)/double(n);
        double coeff_t_sq = double(3*sum_v)/double(n);
        double coeff_t = double(3*sum_v_sq)/double(n);

        double x = -1.00;
        while(x <= 0) {
            x = (rand()%10);
            double h = eqn(coeff_t_sq, coeff_t, constant, x) / primeEqn( coeff_t_sq, coeff_t, x); 
            while (abs(h) >= ERR) { 
                h = eqn(coeff_t_sq, coeff_t, constant, x) / primeEqn( coeff_t_sq, coeff_t, x);   
                x -= h;
            }
        }
        cout << x << endl;
    }

    return 0;
}