class Solution {
    vector<string> ans;
    
    struct TrieNode {
        char c;
        int wordEnd;
        TrieNode* child[26];
        
        TrieNode(char c) {
            wordEnd = 0;
            this->c  = c;
            
            for(int i=0; i<26; i++) child[i] = NULL;
        }
    };
    
    TrieNode* root;
    
    void insertNode(const string &word) {
        TrieNode* curr = root;
        int index;
        
        for(int i=0; i<word.size(); i++) {
            index = word[i] - 'a';
            
            if(!curr->child[index]) 
                curr->child[index] = new TrieNode(char(97 + index));
            
            curr = curr->child[index];
        }
        
        curr->wordEnd = 1;
    }
    
    bool searchNode(string s) {
        TrieNode* curr =  root;
        int index;
        
        for(int i=0; i<s.size(); i++) {
            index = s[i] - 'a';
            
            if(!curr->child[index]) return false;
            
            curr = curr->child[index];
        }
        
        return curr->wordEnd > 0;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root =  new TrieNode('/');
        
        for(string word : wordDict) 
            insertNode(word);
        
        for(int i=0; i<s.size(); i++) {
            if(searchNode(s.substr(0, i+1))) {
                wordBreakRec(s, s.substr(0, i+1), i+1);
            }
        }
        
        return ans;
    }
    
    void wordBreakRec(const string& s, string st, int pos) {
        if(pos == s.size()) {
            ans.push_back(st);
            return;
        }
        
        st += " ";
        
        for(int i=pos; i<s.size(); i++) {
            if(searchNode(s.substr(pos, i+1-pos))) {
                wordBreakRec(s, st + s.substr(pos, i+1-pos), i+1);
            }
        }
    } 
};
