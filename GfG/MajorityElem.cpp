// Time: O(n)
// Space: O(1)
// Moore's Voting Algorithm

#include <iostream>
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
	    int count = 1;
	    int maxIndex = 0;
	    for(int i=0; i<n; i++) {
	        if(a[maxIndex] == a[i]) {
	            count++;
	        }
	        else
	            count--;
	        if(count == 0) {
	            maxIndex = i;
	            count = 1;
	        }
	    }
	    int pM = a[maxIndex];
	    int final =0;
	    for(int i=0; i<n; i++) {
	        if(a[i] == pM)
	            final++;
	    }
	    if(final>n/2) 
	        cout << pM << endl;
	    else
	        cout << -1 << endl;
	}
	return 0;
}