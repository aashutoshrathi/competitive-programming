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
        string s;
        cin >> s;
        int res = s.size();
        for(int i=0; i<s.size(); i++) {
            if(s[i] > s[i+1]) {
                res = i;
                break;
            }
        }
        string r = "";
        for(int i=0; i<s.size(); i++) {
            if(i!=res)
                r += s[i];
        }
        ll fi = stoi(r);
        cout << fi << endl;
    }
    return 0;
}
