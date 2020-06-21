class Solution {
public:
    int factorial(int n) { 
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
    }
    
    string getPermutation(int n, int k) {
        // fill digits
        vector<int> digs(n);
        iota(digs.begin(), digs.end(), 1);
        
        string res = "";
        int j = n;
        int fact = factorial(n);
        while(digs.size()) {
            if(n == 1) {
                res += to_string(digs[0]);
                digs.pop_back();
                continue;
            }
            fact = fact/j;
            j--;
            
            int i = k/fact - (k%fact == 0);
            
            res += to_string(digs[i]);
            digs.erase(digs.begin() + i);
            
            n = digs.size();
            k -= fact*i;
        }
        return res;
    }
};