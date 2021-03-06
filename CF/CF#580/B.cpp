// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
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

int main() {
    fast
    ll n;
    cin >> n;
    ll res = 0;
    ll temp;
    ll mns = 0, eq = 0;
    for(ll i=0; i<n; i++) {
        cin >> temp;
        res += min(abs(temp-1), abs(temp+1));
        if(abs(temp-1) > abs(temp+1)) {
            mns++;
        }
        if(abs(temp-1) == abs(temp+1)) {
            eq++;
        }
    }
    if(mns%2 == 1) {
        if(eq == 0) {
            res += 2;
        }
    }
    cout << res << endl;
    return 0;
}
