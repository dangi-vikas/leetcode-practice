class RandomizedSet {
    unordered_map<int, int> setIndexes;
    vector<int> set;
    int size = 0;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(setIndexes.find(val) != setIndexes.end())
            return false;
        
        set.push_back(val);
        setIndexes[val] = size;
        size++;
        
        return true;
    }
    
    bool remove(int val) {
        if(setIndexes.find(val) == setIndexes.end())
            return false;
        
        int index = setIndexes[val];
        set[index] = set[size-1];
        set.pop_back(); 
        setIndexes[set[index]] = index;
        setIndexes.erase(val);
        size--;
        
        return true;
    }
    
    int getRandom() {
        return set[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */