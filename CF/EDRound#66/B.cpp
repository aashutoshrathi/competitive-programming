// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
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
#define fcout(a, n) \
for(ll i = 0; i < n; i++) \
    printf("%lld ", a[i]); \
    printf("\n");


int main() {
    fast
    ll t;
    cin >> t;
    ll x = 0;
    stack<ll> st;
    ll times = 1;
    while(t--) {
        string s;
        ll n;
        cin >> s;
        if(x > 4294967295) {
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
        else if(s[0] == 'f') {
            cin >> n;
            st.push(n);
            times *= n;
        } else if(s[0] == 'e') {
            times = times/(st.top());
            if(times > 4294967295) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            st.pop();
        } else {
            x += times;
        }
    }
    if(x > 4294967295) {
        cout << "OVERFLOW!!!" << endl;
        return 0;
    } else {
        cout << x << endl;
        return 0;
    }
    
    return 0;
}