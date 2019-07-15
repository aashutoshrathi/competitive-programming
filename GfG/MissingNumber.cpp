#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n-1];
	    int res = 0;
	    for(int i=0; i<n-1; i++) {
	        cin >> a[i];
	        res ^= a[i];
	        res ^= (i+1);
	    }
	    res ^= n;
	    cout << res << endl;
	}
	return 0;
}