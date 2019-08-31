// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutoshrathi~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

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
typedef long long ll;
#define Y "YES"
#define N "NO"

void solveSmall(ll a[], ll n, ll k) {
    vector<ll> res(n);
    ll one = -1;
    ll two = -1;
    ll fnz = -1;
    fi(n) {
        if(a[i] == 1) {
            if(fnz == -1) {
                fnz = i;
            }
            if(one != -1 && one != i%2) {
                cout << N << endl;
                return;
            } else {
                one = i%2;
            }
        }
        else if(a[i] == 2) {
            if(fnz == -1) {
                fnz = i;
            }
            if(two != -1 && two != i%2) {
                cout << N << endl;
                return;
            } else {
                two = i%2;
            }
        }
    }

    if(one == two && one != -1) {
        cout << N << endl;
        return;
    }
    if(fnz == -1) {
        fi(n) {
            res[i] = i%2 + 1;
        }
    } else {
        if(fnz%2 == one) {
            fi(n) {
                res[i] = i%2 == one ? 1 : 2;
            }
        } else {
            fi(n) {
                res[i] = i%2 == two ? 2 : 1;
            }
        }
    }
    cout << Y << endl;
    fi(n) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void solve(ll a[], ll n, ll k) {
    vector<ll> res(n);
    if(a[0] == -1) {
        a[0] = 1;
    }
    res[0] = a[0];
    for(ll i=1; i<n-1; i++) {
        if(a[i] == -1) {
            for(ll j=1; j<=min(n, k); j++) {
                if(j != a[i-1] && j != a[i+1]) {
                    a[i] = j;
                    res[i] = a[i];
                    break;
                }
            }

            if(a[i] == -1) {
                cout << N << endl;
                return;
            }
        } else {
            res[i] = a[i];
        }
    }

    if(a[n-1] == -1) {
        a[n-1] = k - (a[n-2] == k) ;
        res[n-1] = a[n-1];
    }

    cout << Y << endl;
    fi(n) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        fi(n)
            cin >> a[i];
        if(k>2) {
            solve(a,n,k);       
        } else {
            solveSmall(a, n, k);
        }
    }
    return 0;
}