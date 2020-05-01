// April 7
int countElements(vector<int>& arr) {
    int count = 0;
    unordered_map<int, int> m;
    for(int i: arr) {
        m[i]++;
    }
    
    for(auto i: m) {
        int key = i.first + 1;
        if(m.find(key) != m.end()) {
            count += i.second;
        }
    }
    return count;
}