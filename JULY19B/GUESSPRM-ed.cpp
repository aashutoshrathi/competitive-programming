#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;
 
const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
 
int separator(VI& a)
{
	for(int n = 1; ; ++n)
	{
		set<int> r;
		for(auto i: a)
			r.insert(n * n % i);
		if (SZ(r) == SZ(a))
			return n;
	}
}
 
const int N = 193;
const int M = N * N + 1;
VI classes[M];
bool is_composite[M];
 
int ask(int x)
{
	cout << "1 " << x << endl;
	fflush(stdout);
	cin >> x;
	return x;
}
 
int solve_big_prime()
{
	int x = 31623;
	int v = x * x - ask(x);
	assert(v);
	
	FOR(i, 2, M)
		while (v % i == 0)
			v /= i;
	return v;
}
 
int solve_small_prime(int x)
{
	int g = separator(classes[x]);
	int v = ask(g);
	
	for(auto i: classes[x])
		if (g * g % i == v)
			return i;
	assert(0);
}
 
void solve()
{
	int ans = -1;
	int x = ask(N);
	if (x == N * N)
		ans = solve_big_prime();
	else
		ans = solve_small_prime(x);
	
	cout << "2 " << ans << endl;
	fflush(stdout);
	
	string response;
	cin >> response;
	assert(response == "Yes");
}
 
int main()
{
	FOR(i, 2, M)
		if (!is_composite[i])
		{
			classes[N * N % i].PB(i);
			for(LL j = i *(LL) i; j < M; j += i)
				is_composite[j] = 1;
		}
 
	int tc;
	cin >> tc;
	while(tc--)
		solve();	
	return 0;
} 