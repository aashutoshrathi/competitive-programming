// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
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
typedef long long  ll;

set<ll> factorize(long long n) { 
    set<ll> s;
    ll y = 2;
    while(y*y <= n) {
        if(n%y == 0) {
            s.insert(y);
            n/=y;
        }
        else {
            y++;
        }
    }
    if(n>1) {
        s.insert(n);
    }
    return s;
}

int main() {
    fast
    ll t;
    cin >> t;
    ll x;
    while(t--) {
        string s;
        ll firstOne = 31623LL;
        cout << 1 << " " << firstOne << endl << flush;
        cin >> x;
        ll sqSh = pow(firstOne, 2);
        // cout << sqSh << endl;
        ll divisibleOne = sqSh - x;
        set <ll> ss = factorize(divisibleOne);
        vector<ll> p;
        for(auto it: ss) {
            p.push_back(it);
        }
        ll numOfPr = p.size();

        // cout << "P: ";
        // for (ll i=0; i<p.size(); i++)
        //     cout << p[i] << " ";
        // cout << endl;

        if(numOfPr == 1) {
            cout << 2 << " " << p[0] << endl << flush;
            continue;
        }

        sort(p.begin(), p.end());
        ll biggestOne = p[numOfPr-1];
        ll lastOne = sqrt(biggestOne) + 1;
        cout << 1 << " " << lastOne << endl << flush;
        cin >> x;

        for (ll i=0; i<numOfPr; i++) {
            if((lastOne*lastOne)%p[i] == x) {
                cout << 2 << " " << p[i] << endl << flush;
                break;
            }
        }
        cin >> s;
    }   
    return 42;
}