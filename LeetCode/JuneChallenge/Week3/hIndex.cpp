class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int i = l + (r-l)/2;
            if(citations[i] < n - i) {
                l = i + 1;
            } else {
                r = i - 1;  
            }
        }
        return n - l;
    }
};

