// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
 
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
typedef long long ll;

const ll MOD = 1e9+7;

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n, x;
        cin >> n;
        ll c[n];
        ll total = 0;
        fi(n) {
            cin >> c[i];
            total += c[i];
        }
        cin >> x;
        ll a = total/(x+1);
        ll b = (total*x)/(x+1);
        ll p=0, q=0;
        // cout << a << " " << b << endl;
        ll i=0, box = 0, check = 0;
        while(check<b) {
            check += c[i];
            if(check >= b) {
                box = i;
                break;
            }
            i++;
        }
        p = i+1;
        q = n-i-1;
        cout << p << " " << q << endl;
        
    }
    return 0;
}