// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
// Don't use endl use '\n'

#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai

#define fi(a) for (ll i = 0; i < a; ++i)
#define fj(a) for (ll j = 0; j < a; ++j)
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
#define endl "\n"

void cShift(ll *x, ll *y, ll *z) {
    ll a,b,c;
    a=*z;
    b=*x;
    c=*y;
    *x=a;
    *y=b;
    *z=c;
}

string makeAString(ll a, ll b, ll c) {
    string x = to_string(a) + ' ' + to_string(b) + ' ' + to_string(c);
    return x;
}

void log(ll p[], ll n) {
    cout << "Array log" << endl;
    for(int i=1; i<=n; i++) {
        cout << p[i] << ' ';
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
        ll p[n+1];
        ll wp = 0;
        bool err = false;
        vector<string> res;

        for(int i=1; i<=n; i++) {
            cin >> p[i];
            if(p[i] != i) {
                wp++;
            }
        }
        
        if(wp == 2) {
            err = true;
        }

        if(!err) {
            // easy cases
            for(int i=1; i<=n; i++) {
                ll a, b, c;
                if(k < 0) {
                    err = true;
                    break;
                }

                while(p[i] != i && p[p[i]] != i && k >= 0) {
                    a = i;
                    b = p[i];
                    c = p[p[i]];
                    cShift(&p[a], &p[b], &p[c]);
                    string x = makeAString(a, b, c);
                    // cout << x << endl;
                    res.push_back(x);
                    k--;
                }
            }

            if(k >= 0) {
                // tough cases
                for(int i=1; i<=n; i++) {
                    ll a = 0, b = 0, c = 0;
                    if(k < 0) {
                        err = true;
                        break;
                    }
                    
                    while(p[i] != i && k>= 0) {
                        a = i;
                        b = p[i];
                        for(int j=i+1; j<=n; j++) {
                            if(p[j] != j && j!=p[i]) {
                                c = j;
                                break;
                            }
                        }
                        ll diff = 0;
                        for(int k=1; k<=n; k++) {
                            if(k != p[k])
                                diff++;
                        }
                        if(diff == 2)
                            break;
                        if(c) {
                            cShift(&p[a], &p[b], &p[c]);
                            string x = makeAString(a, b, c);
                            // cout << x << endl;
                            res.push_back(x);
                            k--;
                        }
                    }
                }
            }
            
            
            for(int i=1; i<=n; i++) {
            	// cout << i << ": " << p[i] << endl;
                if(i != p[i]) {
                    err = true;
                    break;
                }
            }
        }

        if(err) {
            cout << -1 << '\n';
        } else {
            cout << res.size() << '\n';
            for(string i: res) {
                cout << i << '\n';
            }
        }   
        
        // log(p, n);
    }
    return 0;
}


/**
Inputs
6
9 4
9 8 7 6 5 4 3 2 1
11 6
2 1 5 7 6 11 4 10 3 9 8
4 2
3 2 4 1
4 2
4 3 2 1
3 2
3 2 1
10 100
10 9 8 7 6 5 4 3 2 1
*/

/*
Outputs:
4
1 9 2
1 8 2
3 7 4
3 6 4
5
3 5 6
3 11 8
3 10 9
1 2 4
1 7 4
1
1 3 4
2
1 4 2
1 3 2
-1
-1
*/