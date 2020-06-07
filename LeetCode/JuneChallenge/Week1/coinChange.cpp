class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> results(amount+1, 0);
        results [0] = 1;
        for(auto i: coins) {
            for(int j=i; j<=amount; j++)
                results[j] += results[j-i];
        }
        return results[amount];
    }
};
