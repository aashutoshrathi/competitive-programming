// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z 

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, k, l, r;
        ll currentTemp, charges;
        
        cin >> n >> m >> k >> l >> r;

        map<ll, ll> bottles;
        bool mila = false;
        for(ll i=0; i<n; i++) {
            cin >> currentTemp >> charges;
            bottles.insert(make_pair(charges, currentTemp));
        }

        for (auto const& i : bottles) {
            ll resultTemp = k;
            if(i.second < k-1) {
                resultTemp = min(k, i.second+m);
            }
            else if(i.second > k+1) {
                resultTemp = max(k, i.second-m);
            }

            if(resultTemp >= l && resultTemp <= r ) {
                mila = true;
                cout << i.first << endl;
                break;
            }
        }
        if(!mila) {
            cout << -1 << endl;
        }
    }
    return 0;
}
