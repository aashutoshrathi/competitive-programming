#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    int start = 0;
	    int end = 0;
        // reverse each word
	    for(int i=0; i<=s.size(); i++) {
	        if(s[i] == '.' || i == s.size()) {
	            end = i-1;
	            while(start < end) {
	                swap(s[start], s[end]);
	                start++;
	                end--;
	            }
	            start = i+1;
	        }
	    }
        // now reverse the string
	    for(int i=s.size()-1; i>=0; i--) {
	        cout << s[i];
	    }
	    cout << endl;
	}
	return 0;
}