// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
 
#include <bits/stdc++.h>// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;// Kyuki yahi mai-baap hai
 
#define MOD             1000000007
#define MIN(n1, n2)     ((n1) > (n2) ? (n2) : (n1))
#define MAX(n1, n2)     ((n1) > (n2) ? (n1) : (n2))
#define MID(s, e)       (s+(e-s)/2)
#define fast fin; fout; fio;
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    if (a == 0)
        return make_tuple(b, 0, 1);

    ll gcd, x, y;
    tie(gcd, x, y) = extended_gcd(b % a, a);

    return make_tuple(gcd, (y - (b/a) * x), x);
}

ll gcd(ll a, ll b) {
    if(a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

string findSum(string str1, string str2) { 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
  
    ll n1 = str1.length(), n2 = str2.length(); 
    ll diff = n2 - n1; 
  
    ll carry = 0; 
  
    for (ll i=n1-1; i>=0; i--) { 
        ll sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (ll i=n2-n1-1; i>=0; i--) { 
        ll sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 

    reverse(str.begin(), str.end()); 
  
    return str; 
}

ll f(string l, string r) {
    string x = l;
    string y;
    string dp = findSum(r, "1");
    while(x != dp) {
        string z = x;
        // f(x)
        for(ll i=z.size() - 1; i>0; i--) {
            if(z[i] == z[i-1]) {
                z[i] = '0';
            }
        }
        // cout << z << endl;
        y = y.size() == 0 ? z : findSum(y, z);
        x = findSum(x, "1");
    }
    ll res = 0;
    for (ll i = 0; i < y.length(); i++)
            res = (res*10 + (ll)y[i] - '0') % MOD;
    return res;
}

int main() {
    fast
    ll t;
    cin >> t;
    while(t--) {
        string l, r;
        ll nl, nr;
        cin >> nl >> l;
        cin >> nr >> r;
        cout << f(l, r) << endl;
    }
    return 0;
}
