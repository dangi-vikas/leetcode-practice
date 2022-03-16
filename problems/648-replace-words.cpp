class Solution {
    struct TrieNode{
        vector<TrieNode*> children{26, nullptr};
        bool ends = false;
        string word;
    };
    
    class Trie {
    public:
        TrieNode* head = NULL;

        Trie(){
            head = new TrieNode();
        }

        void insert(string s){
            TrieNode* ptr = head;

            for(auto it : s) {
                if(!ptr->children[it-'a'])
                    ptr->children[it-'a'] = new TrieNode();

                ptr = ptr->children[it-'a'];
            }

            ptr->ends = true;
            ptr->word = s;
        }

        string search(string s){
            TrieNode* ptr = head;

            for(auto it : s){
                if(!ptr) break;
                if(ptr->ends) return ptr->word;

                ptr = ptr->children[it-'a'];
            }

            return s;
        }
    };
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* T = new Trie();
        
        for(auto it:dictionary) T->insert(it);
        
        string ans = "";
        string word = "";
        
        for(auto it : sentence){
            if(it == ' '){
                string successor = T->search(word);
                ans += successor;
                ans += " ";
                word = "";
            }
            
            else word += it;
        }
        
        string successor = T->search(word);
        ans += successor;
        
        return ans;
    }
};