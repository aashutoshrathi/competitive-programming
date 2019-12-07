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
#define tezzzzz fin; fout; fio;
#define pb push_back
#define fin cin.tie(NULL)
#define fout cout.tie(NULL)
#define fio ios::sync_with_stdio(false)
typedef pair <long, long> lpairs;
typedef long long ll;
#define endl "\n"

const ll MOD = 1e9+7;

void print(queue<ll>& Queue) { 
    while (!Queue.empty()) { 
        cout << Queue.front() << " "; 
        Queue.pop(); 
    } 
} 
  
// Function to reverse the queue 
void reverseQueue(queue<ll>& Queue) { 
    stack<ll> Stack; 
    while (!Queue.empty()) { 
        Stack.push(Queue.front()); 
        Queue.pop(); 
    } 
    while (!Stack.empty()) { 
        Queue.push(Stack.top()); 
        Stack.pop(); 
    } 
} 

int main() {
    tezzzzz
    ll n, k;
    cin >> n >> k;
    ll x;
    queue<ll> ans;
    map<ll, bool> m;
    fi(n) {
        cin >> x;
        if(m[x]) {
            continue;
        }

        if(!m[x] && ans.size() < k) {
            ans.push(x);
            m[x] = 1;
        }

        else if(ans.size() >= k) {
            ans.push(x);
            m[x] = 1;
            m[ans.front()] = 0;
            ans.pop();
        }

    }
    cout << ans.size() << endl;
    reverseQueue(ans);
    print(ans);
    return 0;
}
