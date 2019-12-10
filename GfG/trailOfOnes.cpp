#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;

	    int a[n], b[n]; // a are string of length i, which ends with 0 and b are strings of length i which ends with 1.
	    a[0] = b[0] = 1;
	    for(int i=1; i<n; i++) {
	        a[i] = a[i-1] + b[i-1];
	        b[i] = a[i-1];
	    }

	    int to = 1<<n; // total string
	    cout << to - a[n-1] - b[n-1] << endl; // minus those with no consecutive ones.
	}
	return 0;
}