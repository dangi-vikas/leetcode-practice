class WordDictionary {

    struct TrieNode {
        char val;
        int endsHere;
        TrieNode* child[26];
    };

    TrieNode* getNode(char index){
        TrieNode* newNode = new TrieNode;

        newNode->val = index;
        newNode->endsHere = 0;

        for(int i=0; i<26; i++)
            newNode->child[i] = NULL;

        return newNode;
    }

    TrieNode* root = getNode('/'); 
    
    void insert(string word) {
        TrieNode* curr = root;
        int index;
        
        for(int i=0; word[i]!='\0'; i++){
            index = word[i] - 'a';
            
            if(!curr->child[index])
                curr->child[index] = getNode(word[i]);
            
            curr = curr->child[index];
        }
        
        curr->endsHere++;
    }
    
    bool searchRec(string s, TrieNode* curr, int pos, int n) {
        if(s[pos] == '.'){
            bool res = false;
            TrieNode* current = curr;
            
            for(int i=0; i<26; i++){
                if(pos==n-1 && curr->child[i]){
                    current = curr->child[i];
                    res |= current->endsHere > 0;
                }
                else if(curr->child[i] && searchRec(s, curr->child[i], pos+1, n))
                    return true;
            }
            return res;
        }
        
        else if(curr->child[s[pos]-'a']){
            if(pos==n-1){
                curr = curr->child[s[pos]-'a'];
                return curr->endsHere > 0;
            }
            return searchRec(s, curr->child[s[pos]-'a'], pos+1, n);
        }
        
        return false;
    }
    
public: 
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        insert(word);
    }
    
    bool search(string word) {
        return searchRec(word, root, 0, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */