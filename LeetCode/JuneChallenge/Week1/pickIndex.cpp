class Solution {
public:
    vector<int> weights;
    Solution(vector<int>& w) {
        int s = 0;
        for(auto i: w) {
            s += i;
            weights.push_back(s);
        }
    }
    
    int pickIndex() {
        int n = weights.size();
        int rndIndex = rand() % weights[n-1];
        for(int i=0; i<n; i++)
            if(rndIndex < weights[i]) 
                return i;   
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
