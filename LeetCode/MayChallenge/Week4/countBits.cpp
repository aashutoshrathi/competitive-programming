class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int current_power = 0;
        for(int i=0; i<=num; i++) {
            if(i && !(i&(i-1))) {
                current_power = i;
            }
            /*
            Observing that it follows a pattern for each power of 2.
            Like 0 -> 0 and 1 -> 1,
            and after that for every power of 2 (n) it is +1 from (0, n/2)
            */
            res.push_back(i < 2 ? i : res[i-current_power] + 1);
        }
        
        return res;
    }
};