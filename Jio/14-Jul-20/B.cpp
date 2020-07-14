// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~ Aashutosh Rathi~~~~~~
// ~~~~~~~~aashutosh001~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Use memcpy while copying matrix :D
// o_O Never do calculation in if block -_- 
// Use __builtin_popcount(z) to get set bit count of z
// Don't use endl use '\n'
// To make pair use {a, b}

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
typedef unsigned long long ull;
#define endl "\n"
// Use more random comments to keep unique
const ll MOD = 1e9+7;

ll power(ll x, ll y, ll p) { 
    ll res = 1;
    x = x % p;
  
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}
  
ll modInverse(ll n, ll p) { 
    return power(n, p-2, p); 
}

vector<int> primes;

void SieveOfEratosthenes(int n) {
    primes.clear();
    bool prime[n+1];
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) {
       if (prime[p]) {
           primes.push_back(p);
       }
    } 
}

template<typename T>
void pop_front(std::vector<T>& vec) {
    assert(!vec.empty());
    vec.erase(vec.begin());
}

int main() {
    tezzzzz
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        char grid[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> grid[i][j];
        
        for(int i=0; i<n; i++) {
            queue<pair<int,int> > tq;
            tq.push(make_pair(i, 0));

            while(!tq.empty()) {
                pair<int,int> top = tq.front();
                tq.pop();
                int a = top.first; int b = top.second;
                if(grid[a][b] == '.') {
                    grid[a][b] = '*';
                    int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                    for(int i = 0; i < 4; i++)  
                        tq.push(make_pair( a + changeX[i], b + changeY[i] ));
                }
            }
            
            tq.push(make_pair(i, m-1));
            while(!tq.empty()) {
                pair<int,int> top = tq.front();
                tq.pop();
                int a = top.first; int b = top.second;
                if(grid[a][b] == '.') {
                    grid[a][b] = '*';
                    int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                    for(int i = 0; i < 4; i++)  
                        tq.push(make_pair( a + changeX[i], b + changeY[i] ));
                }
            }
        }

        for(int i=0; i<m; i++) {
            queue<pair<int,int> > tq;
            tq.push(make_pair(0, i));

            while(!tq.empty()) {
                pair<int,int> top = tq.front();
                tq.pop();
                int a = top.first; int b = top.second;
                if(grid[a][b] == '.') {
                    grid[a][b] = '*';
                    int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                    for(int i = 0; i < 4; i++)  
                        tq.push(make_pair( a + changeX[i], b + changeY[i] ));
                }
            }
            
            tq.push(make_pair(n-1, i));
            while(!tq.empty()) {
                pair<int,int> top = tq.front();
                tq.pop();
                int a = top.first; int b = top.second;
                if(grid[a][b] == '.') {
                    grid[a][b] = '*';
                    int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                    for(int i = 0; i < 4; i++)  
                        tq.push(make_pair( a + changeX[i], b + changeY[i] ));
                }
            }
        }

        ll numIslands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '.'){
                    numIslands++;
                    queue<pair<int,int> > q;
                    q.push(make_pair(i, j));
                    
                    while(!q.empty()) {
                        pair<int,int> top = q.front();
                        q.pop();
                        int a = top.first; int b = top.second;
                        
                        if(a < 0 or b < 0 or a >= n or b >= m or grid[a][b] != '.') 
                            continue;
                        else {
                            grid[a][b] = '#';
                            int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                            for(int i = 0; i < 4; i++)  
                                q.push(make_pair( a + changeX[i], b + changeY[i] ));
                        }
                    }
                }
            }
        }
        cout << numIslands << endl;
    }  
    return 0;
}
