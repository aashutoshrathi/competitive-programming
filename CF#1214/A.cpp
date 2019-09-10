// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
#include <bits/stdc++.h>// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;    // Kyuki yahi mai-baap hai

#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef long long ll;
#define pb push_back
#define LIM 1e8

int main() {
    ll n, d, e;
    cin >> n >> d >> e;
    e = 5*e;
    ll res = INT_MAX;
    for(ll i=0; i<=(LIM/d); i+=d) {
        if((n-i)%e >= 0) {
            res = min(res, (n-i)%e);
        }
    }
    cout << res << endl;
    return 0;
}
