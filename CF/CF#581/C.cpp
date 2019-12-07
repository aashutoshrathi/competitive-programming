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
    ll n;
    cin >> n;
    string s;
    vector<string> adj;
    vector<ll> rsum;
    for(int i=0; i<n; i++) {
        cin >> s;
        adj.push_back(s);
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            sum += s[i]-'0';
        }
        rsum.push_back(sum);
    }
    ll m,x;
    cin >> m;
    vector<ll> path;
    for(int i=0; i<m; i++) {
        cin >> x;
        path.push_back(x);
    }

    vector<ll> final;
    final.push_back(path[0]);
    int i = 1, j =1;
    while(j != m) {
        i++;
        while(adj[path[i-1]][path[i]] == 1 && rsum[i] == 1 && i != m) {
            i++;
        }
        cout << path[i] << " ";
        j = i;
    }


    return 0;
}
