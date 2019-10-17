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

string solve(string s, int z) {
    for(int i=0; i<z; i++) {
        int m = 0, n = 0;
        if(s[i] != '.') {
            int y = s[i] - '0';
            m = max(0, i-y);
            n = min(z-1, i+y);
            for(int j=m; j<=n; j++) {
                if(s[j] != '.' && i!=j) {
                    // cout << i << " " << j << endl;
                    return "unsafe";
                }
            }
            s[n] = '0'; s[m] = '0';
        }
    }
    return "safe";
}

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int z = s.size();
        cout << solve(s, z) << endl;
    }
    return 0;
}
