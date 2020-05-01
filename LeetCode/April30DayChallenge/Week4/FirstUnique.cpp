class FirstUnique {
public:
    queue<int> v;
    unordered_map<int, int> m;
    
    FirstUnique(vector<int>& nums) {
        for(auto i: nums) {
            add(i);
        }
    }
    
    int showFirstUnique() {
        while(!v.empty() && m[v.front()] > 1) {
            v.pop();
        }
        if(v.empty()) {
            return -1;
        }
        return v.front();
    }
    
    void add(int value) {
        v.push(value);
        m[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */