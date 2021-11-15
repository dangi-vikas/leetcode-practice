class Trie {
    struct TrieNode {
        char val;
        int count;
        int endsHere;
        TrieNode* child[26];
    };
    TrieNode* root;
    
    //creates a new node
    TrieNode* getNode(int index){
        TrieNode* newNode = new TrieNode;
        
        newNode->val = 'a' + index;
        newNode->count = newNode->endsHere = 0;
            
        for(int i=0; i<26; i++)
            newNode->child[i] = NULL;
        
        return newNode;
    }
    
public:

    //initializes the trie object
    Trie() {
          root = getNode('/' - 'a');  
    }
    
    //inserts the string word into the trie
    void insert(string word) {
        TrieNode* curr = root;
        int index;
        
        for(int i=0; word[i]!='\0'; i++){
            index = word[i] - 'a';
            
            if(!curr->child[index])
                curr->child[index] = getNode(index);
            
            curr->child[index]->count++;
            curr = curr->child[index];
        }
        
        curr->endsHere++;
    }
    
    //returns whether the string word is in the trie (i.e., was inserted before)
    bool search(string word) {
        TrieNode* curr = root;
        int index;
        
        for(int i=0; word[i]!='\0'; i++){
            index = word[i] - 'a';
            
            if(!curr->child[index])
                return false;   
            
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    //returns if there is a previously inserted string word that has the prefix prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int index;
        
        for(int i=0; prefix[i]!='\0'; i++){
            index = prefix[i] - 'a';
            
            if(!curr->child[index])
                return false;   
            
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */