// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define fj(a) for (ll j = 0; j < a; ++j)
#define fi(a) for (ll i = 0; i < a; ++i)
#define mod(x) 			x%1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef unsigned long long ll;

ll fib(ll n) {
    string s = "011235831459437077415617853819099875279651673033695493257291";
    return s[n]-'0';
}

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll des = 0;
        while(n>1){
            des++;
            n = n/2;
        }

        ll ind = pow(2, des);
        ind = (ind)%60 - 1;
        cout << fib(ind)%10 << endl;
    }
    return 0;
}