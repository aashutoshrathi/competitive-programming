// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ G103 Wale ~~~~~~
// ~~~~~~~~array_n00bs~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
#include <bits/stdc++.h>// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;    // Kyuki yahi mai-baap hai

#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef long long ll;
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll c, x;
        cin >> c >> x;
        ll res = 0;
        while(c > 0) {
            res += c%x;
            c = c/x;
        }
        cout << res << endl;
    }
}
