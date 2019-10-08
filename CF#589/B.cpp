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

int main() {
    tezzzzz
    int h, w, flag=0;
    cin >> h >> w;
    
    int mat[h][w];
    memset(mat,0,sizeof(mat));

    for(int i = 0; i < h; i++) {
		int r;
		cin >> r;
		for(int j = 0; j < r; j++) 
            mat[i][j] |= 1;
		if(r < w) mat[i][r] |= 2;
	}

	for(int i = 0; i < w; i++) {
		int c;
		cin >> c;
		for(int j = 0; j < c; j++) 
            mat[j][i] |= 1;
		if(c < h) mat[c][i] |= 2;
	}

	int ans = 1;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(mat[i][j] == 3) {
				ans *= 0;
			}
			if(mat[i][j] == 0) {
				ans = (ans*2)%MOD;
			}
		}
	}
	cout << ans%MOD << '\n';
    
    return 0;
}
