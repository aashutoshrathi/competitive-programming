class Solution {
public:
    string coolThings(string S) {
        stack<char> x;
        for(auto i: S) {
            if(i!='#') {
                x.push(i);
            } else if(!x.empty()) {
                x.pop();    
            }
        }
        string s;
        while(!x.empty()) {
            s += x.top();
            x.pop();
        }
        return s;
    }
    bool backspaceCompare(string S, string T) {
        string s = coolThings(S);
        string t = coolThings(T);
        
        return s.compare(t) == 0;
    }
};