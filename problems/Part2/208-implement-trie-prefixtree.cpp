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


//BETTER METHOD


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


 class TrieNode {
public:
    vector<TrieNode*> links = vector<TrieNode*>(26, 0);
    bool isEnd = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEnd = true;
    }
};

class Trie {
    TrieNode* root;

public:
    //initializes the trie object
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))    
                node->put(word[i], new TrieNode());
            
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    //returns whether the string word is in the trie (i.e., was inserted before)
    bool search(string word) {
        TrieNode* node = root;

        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))
                return false;

            node = node->get(word[i]);
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(int i=0; i<prefix.length(); i++) {
            if(!node->containsKey(prefix[i]))
                return false;

            node = node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */