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

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        unordered_map<string, vector<int>> m;
        int n;
        cin >> n;
        ll res = 0;
        for(int i=0; i< n; i++) {
            string s;
            int x;
            cin >> s >> x;
            if(m.find(s) == m.end()) {
                m[s].push_back(0);
                m[s].push_back(0);
                m[s][x]++;
            } else {
                m[s][x]++;
            }
        }
        for(auto i: m) {
            res += max(i.second[0], i.second[1]);
        }
        cout << res << endl;
    }
    return 0;
}
