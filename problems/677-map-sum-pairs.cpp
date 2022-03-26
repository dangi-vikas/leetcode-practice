class Trie{
private:
    int val;
    vector<Trie*> child{26};
    
public:
    Trie(int x) : val(x){
        int i;
        for(i=0; i<26; i++){
            child[i] = NULL;
        }
    }
    
    void insert(string s, int val){
        Trie* temp = this;
        int n = s.size();
        int i, ind;
        
        for(i=0; i<n; i++){
            ind = s[i] - 'a';
            
            if(temp->child[ind]) {
                temp = temp->child[ind]; 
                temp->val += val;
            }
            
            else {
                temp->child[ind] = new Trie(val);
                temp = temp->child[ind];
            }
        }
    }
    
    int findValue(string s){
        Trie* temp = this;
        int n = s.size();
        int i, ind;
        
        for(i=0; i<n; i++){
            ind = s[i] - 'a';
            if(temp->child[ind]) temp = temp->child[ind];
            else return 0;
        }
        
        return temp->val;
    }
    
};

class MapSum {
    unordered_map<string,int> mp;
    Trie* root;
    
public:
    MapSum() : root (new Trie(0)) {
        mp.clear();
    }
    
    void insert(string key, int val) {
        int insertVal = val;
        
        if(mp.find(key) != mp.end())
            insertVal = val - mp[key];
        
        mp[key] = val;
        root->insert(key, insertVal);
    }
    
    int sum(string prefix) {
        return root->findValue(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */class Trie{
private:
    int val;
    vector<Trie*> child{26};
    
public:
    Trie(int x) : val(x){
        int i;
        for(i=0; i<26; i++){
            child[i] = NULL;
        }
    }
    
    void insert(string s, int val){
        Trie* temp = this;
        int n = s.size();
        int i, ind;
        
        for(i=0; i<n; i++){
            ind = s[i] - 'a';
            
            if(temp->child[ind]) {
                temp = temp->child[ind]; 
                temp->val += val;
            }
            
            else {
                temp->child[ind] = new Trie(val);
                temp = temp->child[ind];
            }
        }
    }
    
    int findValue(string s){
        Trie* temp = this;
        int n = s.size();
        int i, ind;
        
        for(i=0; i<n; i++){
            ind = s[i] - 'a';
            if(temp->child[ind]) temp = temp->child[ind];
            else return 0;
        }
        
        return temp->val;
    }
    
};

class MapSum {
    unordered_map<string,int> mp;
    Trie* root;
    
public:
    MapSum() : root (new Trie(0)) {
        mp.clear();
    }
    
    void insert(string key, int val) {
        int insertVal = val;
        
        if(mp.find(key) != mp.end())
            insertVal = val - mp[key];
        
        mp[key] = val;
        root->insert(key, insertVal);
    }
    
    int sum(string prefix) {
        return root->findValue(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */