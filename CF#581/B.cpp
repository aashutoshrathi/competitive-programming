// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
#include <bits/stdc++.h>// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;    // Kyuki yahi mai-baap hai
 
#define mod(x)          x%1000000007
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
    ll n,l,r;
    cin >> n >> l >> r;
    ll minwa = n;
    ll maxwa = 0;
    minwa = (n-l) + (1 << l) - 1;
    cout << minwa << " ";
    if(r >= n) {
        maxwa = (1 << n) - 1;
    } else {
        maxwa = (1 << r) - 1 + (n-r)*(1 << (r-1)); 
    }
    cout << maxwa << endl;
    return 0;
}
