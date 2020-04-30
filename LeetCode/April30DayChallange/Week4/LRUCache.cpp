class LRUCache {
public:
    int cap;
    list<int>key_list;
    unordered_map<int,int> m;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end() ) 
            return -1;
        
        else {
            key_list.remove(key);
            key_list.push_back(key);
            return m[key];
        }   
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end() ){
            m.erase(key);
            key_list.remove(key);
        }
        if(key_list.size() == cap){
            int temp = key_list.front();
            key_list.pop_front();
            m.erase(temp);
        }
        m[key] = value;
        key_list.push_back(key);
    }
};