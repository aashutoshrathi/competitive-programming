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
    string s;
    cin >> s;
    ll x = s.size();
    ll sum = 0;
    ll nz = 0;
    if(s == "0") {
        cout << 0 << endl;
        return 0;
    }
    for(ll i=0; i<x; i++) {
        sum += s[i]-'0';
        if(s[i] == '0') {
            nz++;
        }
    }
    cout << (x-1)/2 + 1 - (sum == 1 && nz%2 == 0) << endl;
    return 0;
}
