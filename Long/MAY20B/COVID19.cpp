// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
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

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        int a = INT_MAX, b = INT_MIN;
        fi(n) cin >> arr[i];
        
        int res = 1;
        
        for(int i=1; i<n; i++) {
            int diff = arr[i] - arr[i-1];
            if(diff < 3) {
                res++;
            } else {
                a = MIN(res, a);
                b = MAX(res, b);
                res = 1;
            }
        }
        a = MIN(res, a);
        b = MAX(res, b);
        
        cout << a << " " << b << endl;
    }
    return 0;
}