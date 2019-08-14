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

ll cnt[2000020];
ll sum[2000020];
ll a[100010];

int main() {
    fast
    ll t;
    cin >> t;
    cnt[0] = 1;
    sum[0] = 1;
    while(t--) {
        ll n;
        ll s = 0, res = 0;
        cin >> n;
        for(ll i=1; i<=n; ++i) {
            cin >> a[i];
            s ^= a[i];
            res += cnt[s]*i - sum[s];
            ++cnt[s];
            sum[s] += i+1;
        }

        cout << res << endl;

        s=0;
		for(int i=1;i<=n;++i) {
			s^=a[i];
			--cnt[s];
			sum[s] -= i+1;
		}
    }
    return 0;
}
