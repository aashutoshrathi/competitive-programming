#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    vector<int> v;
	    int curMax = -1;
	    for(int i=n-1; i>=0; i--) {
	        if(a[i] >= curMax) {
	            v.push_back(a[i]);
	            curMax = a[i];
	        }
	    }
	    for(auto x = v.crbegin() ; x!=v.crend() ; x++){
            cout << *x << " ";
        }
        cout << endl;
        v.clear();
	}
	return 0;
}