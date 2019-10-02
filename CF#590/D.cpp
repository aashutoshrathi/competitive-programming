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
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;
#define endl "\n"

const ll MOD = 1e9+7;

int main() {
    tezzzzz
    string s;
    cin >> s;
    vector<set<int>> repo(26);

    for(int i=0; i<s.size(); ++i) {
        repo[s[i]-'a'].insert(i);
    }

    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        --y;
        if(x == 1) {
            char z;
            cin >> z;
            repo[s[y]-'a'].erase(y);
            s[y] = z;
            repo[s[y]-'a'].insert(y);
        }
        else {
            int z;
            cin >> z;
            --z;
            ll res = 0;
            for(int i=0; i<26; ++i) {
                auto it = repo[i].lower_bound(y);
                if (it != repo[i].end() && *it <= z) ++res;
            }
            cout << res << endl;
        }
    }
    
    return 0;
}
