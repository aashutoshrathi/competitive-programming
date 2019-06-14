// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
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



int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        string s;
        cin >> s;
        float p = 0, a = 0, scope = 0;
        for(int i=0; i<d; i++) {
            if(s[i] == 'P') {
                p++;
            }
            else if(s[i] == 'A') {
                a++;
            }

            if(i >= 2 && i < d-2) {
                if(s[i] == 'A' && (s[i-1] == 'P' || s[i-2] == 'P') && (s[i+1] == 'P' || s[i+2] == 'P')) {
                    scope++;
                }
            }
        }
        float haalat = p/float(d);
        ll need = MAX(0, ceil(0.75*(d) - p));
        if(scope >= need) {
            cout << need << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}

