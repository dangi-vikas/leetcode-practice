class MagicDictionary {
    unordered_map<string, int> magicDict;
    
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
       for(int i=0; i<dictionary.size(); i++) 
           magicDict[dictionary[i]]++;
    }
    
    bool search(string searchWord) {
        int length = searchWord.length();
        
        for(auto i=magicDict.begin(); i!=magicDict.end(); i++) {
            if(i->first.length() == length) {
                int diff = 0;
                
                for(int j=0; j<length; j++)
                    if(i->first[j] != searchWord[j])
                        diff++;
                
                if(diff == 1) return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */