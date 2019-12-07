// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;	// Kyuki yahi mai-baap hai
 
#define mod(x) 			x%1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;

ll gcd(ll a,ll b){
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
	if (a == 0)
		return make_tuple(b, 0, 1);

	ll gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        ll n, z;
        vector<ll> v;
        cin >> n;
        ll p1 = 0, p2 = 0;

        for(ll i=0; i<n; i++) {
            cin >> z;
            v.push_back(z);
        }

        ll ansOne = INT_MIN, ansTwo = INT_MIN;

        for(ll i=0;i<n;i++) {
            if(ansOne < v[i]) {
                p1 = i;
            }
            ansOne = max(ansOne, v[i]);
        }

        for(ll i=0;i<n;i++) {
            if(i!=p1 && v[i]<ansOne && ansTwo<v[i]) {
                ansTwo = v[i];
                p2 = i;
            }
        }

        if(ansTwo == INT_MIN) {
            cout << 2*ansOne << endl;
            continue;
        }

        ll x = ansTwo, y = ansOne;
        for(ll i=0; i<n; i++) {
            if(i!=p1 && v[i]!=ansOne)
                x=gcd(v[i],x);
            if(i!=p2 && v[i]!=ansTwo)
                y=gcd(v[i],y);
        }
        cout << max(x+ansOne, y+ansTwo) << endl;
    }
    return 0;
}