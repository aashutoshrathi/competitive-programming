// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Never use endl unless needed

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fj(a) for (ll j = 0; j < a; ++j)
#define fi(a) for (ll i = 0; i < a; ++i) 
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef unsigned long long ll;

const ll MOD = 1e9+7;
const ll LIM = 1000009;

ll pop[LIM] = {0};

void popu() {
    pop[1] = 1;
    pop[2] = 2;
    ll res = 2;
    for(ll i=3; i<=LIM; i++) {
        res = ((res%MOD)*i)%MOD;
        pop[i] = ((pop[i-1]%MOD)*(res%MOD))%MOD;
    }
}

int main() {
    fast
    ll t;
    popu();
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << pop[n] << "\n";
        // fi(n + 1)
        //     cout << pop[i] << " ";
        // cout << endl;
    }
    return 0;
}