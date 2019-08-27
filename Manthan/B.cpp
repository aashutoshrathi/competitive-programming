// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/contest/1208/problem/B
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai
 
#define mod(x) 			x%1000000007;
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;
#define fcout(a, n) \
for(ll i = 0; i < n; i++) \
    printf("%lld ", a[i]); \
    printf("\n");


int main() {
    fast
    int t;
    cin >> t;
    ll a[t];
    for(int i=0; i<t; i++) {
        cin >> a[i];
    }
    int l = t;
    
    // Base Case
    map<ll, ll> m;
    int r = -1;

    for(int i=0; i<t; i++) {
        if(m[a[i]] > 0) {
            l = i;
            break;
        } else {
            m[a[i]]++;
        }
    }

    if(l == t) {
        cout << 0 << endl;
        return 0;
    }

    m.clear();

    for(int i=t-1; i>=0; i--) {
        if(m[a[i]] > 0) {
            r = i+1;
            break;
        } else {
            m[a[i]]++;
        }
    }

    m.clear();

    int ans = r;
    for(int i=0; i<l; i++) {
        ll j = t - 1;
        m[a[i]]++;
        while(j >= r)
        {
            if(m.find(a[j]) != m.end())
                break;
            j--;
        }
        ans = MIN(ans, j - i);
    }
    cout << ans << endl;
    
    return 0;
}

