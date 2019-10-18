// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// one last time
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fi(a) for (ll i = 0; i < a; ++i)
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
#define Y "YES"
#define N "NO"

struct LS{
    ll l, r, v;
};

bool compareByVel(const LS &a, const LS &b) {
    return a.v < b.v;
}

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<LS> vc;
        while(n--) {
            ll v, l, r;
            cin >> l >> r >> v;
            vc.push_back({l, r, v});
        }
        sort(vc.begin(), vc.end(), compareByVel);
        map<ll, ll> m;
        bool fl = 1;
        vector<pair<int, int>> po;
        for (ll i=0; i<vc.size()-1; i++) {
            // for (ll i=0; i<vc.size(); i++) {
            //     same[vc[i].v].push_back(vc[i]);
            // }
            if(vc[i].v == vc[i+1].v) {
                if(!(vc[i].r < vc[i+1].l || vc[i+1].r < vc[i].l)) {
                    // cout << vc[i].l << endl;
                    m[vc[i].v]++;
                    if(i == vc.size()-2) {
                        m[vc[i].v]++;
                    }
                    if(m[vc[i].v] > 2) {
                        cout << N << endl;
                        fl = 0;
                        break;
                    }
                    int iL = max(vc[i].l, vc[i+1].l);
                    int iH = min(vc[i].l, vc[i+1].l);
                    for(int j =0; j < po.size(); j++) {
                        if(!(po[j].first < iL || (iH < po[j].second))) {
                            cout << N << endl;
                            fl = 0;
                            break;
                        }
                    }
                    po.push_back(make_pair(iL, iH));
                    vc[i+1].l = min(vc[i].l, vc[i+1].l);
                    vc[i+1].r = max(vc[i].r, vc[i+1].r);
                }
            }
        }
        if(fl) {
            cout << Y << endl;
        }
    }
    return 0;
}
