class Solution {
public:
    int maxProfit(vector<int>& prices) {     
    int buy = INT_MIN, sell = 0, p_sell = 0;
        for(int i: prices){
            int p_buy = buy;
            buy = max(buy, p_sell - i);
            p_sell = sell;
            sell = max(sell, p_buy + i);  
        }
        return sell;
    }
};
