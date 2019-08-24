// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/problemset/problem/489/C
 
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
    ll m, s;
    cin >> m >> s;

    // when s is 0 or greater than 9m
    if(s == 0 && m == 1 ) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    if(s == 0 || (s > 9*m)) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    ll sCopyOne = s;
    ll helper;
    // Min part
    for(int i=0; i < m; i++) {
        helper = MAX(i==0, sCopyOne-(9*(m-i-1)));
        cout << helper;
        sCopyOne -= helper;
    }
    cout << " ";

    sCopyOne = s;
    // Max part
    for(int i=0; i < m; i++) {
        cout << MIN(9, sCopyOne);
        sCopyOne -= MIN(9, sCopyOne);
    }
    cout << endl;

    return 0;
}

