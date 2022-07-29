class TrieNode {
public:
    int idx = -1;
    TrieNode* words['z'-'a' + 1] = {NULL,};
};

class Solution {
    vector<vector<int>> ans;
    int n = -1;
    TrieNode* root = new TrieNode();
    
    void insert(string &word, TrieNode* root, int idx) {
        for(int i=0; i<word.length(); i++) {
            if(!(root->words[word[i] - 'a'])) 
                root->words[word[i] - 'a'] = new TrieNode();
            
            root = root->words[word[i] - 'a'];
        }
        
        root->idx = idx;
        return;
    }
    
     bool isPalindrome(const string &word) {
        int end = word.length();
        --end;
        int s = 0;
         
        while(s < end) {
            if(word[s] != word[end]) return false;
            s++; end--;
        }
         
        return true;
    }
    
    void getBig(TrieNode* curr, string & t, int idx) {
        for(int i=0; i<26; i++) {
            if(curr->words[i] == NULL) continue;
            
            t.push_back('a' + i);
            
            if(curr->words[i]->idx != -1 && isPalindrome(t)) ans.push_back({idx, curr->words[i]->idx});
            
            getBig(curr->words[i], t, idx);
            t.pop_back();
        }
        
        return;
    }
    
    void getAll(string &word, int idx, TrieNode* curr) {
        for(int i=0; i<word.length(); i++) {
            if(!(curr->words[word[i] - 'a'])) return;
            
            curr = curr->words[word[i] - 'a'];
            
            if(curr->idx != -1 && curr->idx != idx && ((i+1) == word.length() || isPalindrome(word.substr(i+1))))
                ans.push_back({idx, curr->idx});
        }
        
        string t;
        getBig(curr, t, idx);
        return;
    }
        
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        n = words.size();
        vector<int> p;
        int blankIdx = -1;
        
        for(int i=0; i<n; i++) {
            if(words[i] == "") {
                blankIdx = i;
                continue;
            }
            
            string word = words[i];
            reverse(begin(word), end(word));
            insert(word, root, i);
            
            if(word == words[i]) p.push_back(i);
        }
        
        if(blankIdx != -1) {
            for(auto i: p) {
                ans.push_back({i, blankIdx});
                ans.push_back({blankIdx, i});
            }
        }
        
        for(int i=0; i<n; i++) {
            if(words[i] == "") continue;
            getAll(words[i], i, root);
        }
        
        return ans;
    }
};