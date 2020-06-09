class Solution {
public:
    static bool comparator(const vector<int>&i, const vector<int>&j) {
        // i.e. descending on height, and then ascending on number of people ahead.
        return (i[0] > j[0] || (i[0] == j[0] && i[1] < j[1]) );
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> betterPeople;
        sort(people.begin(), people.end(), comparator);
        
        // TIL: vector.insert() is cool
        for(auto i: people)
            betterPeople.insert(betterPeople.begin()+i[1], i);
        
        return betterPeople;
        
    }
};