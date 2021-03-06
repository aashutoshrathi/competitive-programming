// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcountll(z) to get set bit count of z
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

void log(int p[], ll n) {
    cout << "Array log" << endl;
    for(int i=1; i<=n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

int mSwap(int p[], int n) { 
	int res = 0; 
	for(int i=1; i<=n; i++) { 
		while (p[i] != i) { 
            int temp = 0;
            swap(p[p[i]], p[i]);
            res++; 
        }
	} 
	return res; 
} 


int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, x, y;
        cin >> n >> m;
        int p[n+1];
        for(int i=1; i<=n; i++) {
            cin >> p[i];
        }
        // Aiming for subtask 1, hence ignoring it first
        fi(m)
            cin >> x >> y;  
        int res = mSwap(p, n);
        cout << res << endl;
    }
    return 0;
}