#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> m;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) {
            return false;
        }
        m[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        int idx = m[val];
        
        swap(arr[idx], arr[arr.size()-1]);
        m[arr[idx]] = idx;
        
        arr.pop_back();
        m.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool a = obj->remove(0);
    bool b = obj->remove(0);
    bool c = obj->insert(0);
    int d = obj->getRandom();
    bool e = obj->remove(0);
    bool f = obj->insert(0);
    return 0;
}