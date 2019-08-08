// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
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
#define N "NO"
#define Y "YES"

ll *constructBITree(ll n) { 
    ll *BITree = new long long[n+1]; 
    for (ll i=1; i<=n; i++) 
        BITree[i] = 0; 
    return BITree; 
}

ll getThatSonOfTree(ll BITree[], ll index) { 
    ll sum = 0;
  
    index++;
    while (index>0) { 
        sum += BITree[index];   
        index -= index & (-index); 
    } 
    return sum; 
}

void updateBIT(ll BITree[], ll n, ll index, ll val) { 
    index++;
    while (index <= n) {
        BITree[index] += val; 
        index += index & (-index); 
    }
} 

void update(ll BITree[], ll l, ll r, ll n, ll val) { 
    updateBIT(BITree, n, l, val);   
    updateBIT(BITree, n, r+1, -val); 
}

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll c[n], h[n];
        bool phasa = false;
        
        ll *b = constructBITree(n);

        for(ll i=0; i<n; i++) {
            cin >> c[i];
        }
        for(ll i=0; i<n; i++) {
            cin >> h[i];
        }

        for(ll i=0; i<n; i++) {
            ll start = MAX(0, i-c[i]);
            ll end = MIN(n-1, i+c[i]);
            update(b, start, end, n, 1); 
        }

        // Sort karo re
        // sort(b, b+n);
        sort(h, h+n);
        
        vector<ll> majaMa;

        for(ll i=0; i<n; i++) {
            majaMa.push_back(getThatSonOfTree(b, i));
        }

        sort(majaMa.begin(), majaMa.end());

        for(ll i=0; i<n; i++) {
            if(majaMa[i] != h[i]) {
                cout << N << endl;
                phasa = true;
                break;
            }
        }
        if(!phasa)
            cout << Y << endl;
    }
    return 0;
}
