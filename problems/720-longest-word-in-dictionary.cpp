class TrieNode{
public:
    bool eow;
    vector<TrieNode*> child;
    
    TrieNode() {
        eow = false;
        child = vector<TrieNode*>(26, nullptr);
    }
};

class Solution { 
    TrieNode* root;
    
public:
    
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        
        for(auto &w : words)
            insert(w);
        
        return longestWordRec(root, "");
    }
    
   void insert(string &word) {
        TrieNode* temp = root;
       
        for(char c : word) {
            int index = c - 'a';
            
            if(temp->child[index])
                temp = temp->child[index];
            
            else {
                temp->child[index] = new TrieNode();
                temp = temp->child[index];
            }
        }
       
        temp->eow = true;
    }
    
    string longestWordRec(TrieNode* node, string curr) {
        string ans = curr;
        
        for(int i=0; i<26; i++) {
            if(node->child[i] && node->child[i]->eow) { 
                curr.push_back('a' + i);
                string temp = longestWordRec(node->child[i], curr);
                curr.pop_back();
                
                if(temp.length() > ans.length()) ans = temp;
            }
        }
        
        return ans;
    }
};