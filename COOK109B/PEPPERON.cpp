 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll x;
        vector<ll> p1;
        vector<ll> p2;
        ll p1f = 0, p2f=0;
        for(ll i=0; i<n; i++) {
            int curr = 0;
            for(ll j=0; j<n; j++) {
                cin >> x;
                if(j<n/2) {
                    curr += x;
                    p1f += x;
                } if(j == n/2 -1) {
                    p1.push_back(curr);
                    curr = 0;
                }
                
                if(j >= n/2) {
                    curr += x;
                    p2f += x;
                }
                if(j == n-1) {
                    p2.push_back(curr);
                }
            }
        }

        for(ll i=0; i<n; i++) {
            cout << p1[i] << " " << p2[i] << endl;
        }

        ll diff = abs(p1f-p2f);
        bool great = p1f>p2f;
        bool equal = p1f==p2f;
        if(equal) {
            cout << 0 << endl;
            return 0;
        }
        ll cmpr = INT_MIN;
        ll res = 0;
        for(ll i=0; i<n; i++) {
            if(great) {
                if(cmpr < (p1[i]-p2[i])) {
                    cmpr = p1[i]-p2[i];
                    // res = diff - cmpr;
                }
            } else {
                if(cmpr < (p2[i]-p1[i])) {
                    cmpr = p2[i]-p1[i];
                    // res = diff - cmpr;
                }
            }
        }
        // cout << cmpr << endl;
    }
    return 0;
}
