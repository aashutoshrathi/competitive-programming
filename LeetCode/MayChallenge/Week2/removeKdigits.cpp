class Solution {
public:
    template<typename T>
    void pop_front(std::vector<T>& vec) {
        assert(!vec.empty());
        vec.erase(vec.begin());
    }
    
    string removeKdigits(string num, int k) {
        if(num.size() == k)
            return "0";
        
        vector<char> v;
        
        for(char i: num) {
            while(k && v.size() && v[v.size()-1] > i) {
                k--;
                v.pop_back();
            }
            v.push_back(i);
        }
        while(k-- && v.size()) {
            v.pop_back();
        }
        
        int i = 0;
        while(v.size() && v[i] == '0') {
            pop_front(v);
        }
        
        string op(v.begin(), v.end());
        if(op == "") {
            op = "0";
        }
        return op;
    }
};
