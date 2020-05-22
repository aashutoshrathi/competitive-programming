class StockSpanner {
public:
    vector<pair<int, int>> tracker;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        int i = tracker.size() - 1;
        while(i >= 0 && price >= tracker[i].first){
            res += tracker[i].second;
            i -= tracker[i].second;
        }
        tracker.push_back({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */