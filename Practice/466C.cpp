// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/problemset/problem/466/C
 
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
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(n < 3 || sum%3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll fsum = 0;
    ll firstPart = 0;
    ll secondPart = 0;

    // Finding first part
    for(ll i=0; i<n; i++) {
        fsum += a[i];
        if(fsum == sum/3) {
            firstPart = i+1;
            break;
        }
    }

    fsum = 0;
    ll zeroesFirst = 0;
    bool zflag = true;
    for(ll i=firstPart; i<n; i++) {
        fsum += a[i];
        if(a[i] == 0 && zflag) {
            zeroesFirst++;
        }
        if(fsum == 0 && sum != 0) {
            zeroesFirst++;
        }
        zflag = a[i] == 0;

        if(fsum == sum/3) {
            secondPart = i+1;
            break;
        }
    }

    ll zeroesSecond = 0;
    zflag = true;
    for(ll i=secondPart; i<n; i++) {
        fsum += a[i];
        if(a[i] == 0 && zflag && i!=n-1 || (sum != 0 && fsum == 0)) {
            zeroesSecond++;
        }
        if(a[i] != 0)
            zflag = false;
    }

    ll res = 1;
    res = res + zeroesFirst + zeroesSecond;
    cout << res << endl;
    return 0;
}

