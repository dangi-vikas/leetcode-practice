class MyHashMap {
    vector<list<pair<int, int>>> v;
    int size;
    
public:
    MyHashMap() {
        size = 1000;
        v.resize(size);
    }
    
    int hash(int key){
        return key % size;
    }
    
    list<pair<int,int>>:: iterator search(int key){
        int i = hash(key);
        list<pair<int, int>> :: iterator it = v[i].begin(); 
        
        while(it != v[i].end()) {
            if(it->first == key) return it;
            it++;
        }
        
        return it; 
    }
    
    void put(int key, int value) {
        int i = hash(key);
        remove(key); 
        v[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        
        if(it == v[i].end()) return -1; 
        return  it->second; 
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key); 
        if(it != v[i].end()) v[i].erase(it); 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */