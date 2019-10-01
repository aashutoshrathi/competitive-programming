#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, char> m;
	m[']'] = '[';
	m['}'] = '{';
	m[')'] = '(';
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    stack<char> a;
	    int c = 0;
	    for(int i=0; i<s.size(); i++) {
	        if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
	            a.push(s[i]);
	            c++;
	        } else {
	            if(!a.empty() && a.top() == m[s[i]]) {
	                a.pop();
	            } else {
	                break;
	            }
	        }
	    }
	    if(a.empty() && c == (s.size()+1)/2) cout << "balanced" << endl;
	    else cout << "not balanced" << endl;
	}
	return 0;
}