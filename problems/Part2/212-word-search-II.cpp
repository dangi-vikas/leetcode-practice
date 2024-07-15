class Solution {
    struct TrieNode {
        char c;
        int wordEnd;
        string word;
        TrieNode* child[26];

        TrieNode(char c) {
            wordEnd = 0;
            this->c  = c;
            word = "";

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

        curr->wordEnd += 1;
        curr->word = word;
    }
    
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode('/');
        
        int n = board.size(), m = board[0].size();
        
        for(string word : words) insertNode(word);
        
        vector<string> ans;
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++)
                findWordsRec(board, i, j, n, m, ans, root);

        return ans;
    }
    
    void findWordsRec(vector<vector<char>>& board, int i, int j, int n, int m, vector<string>& ans, TrieNode* curr) {
        int index = board[i][j] - 'a';
        
        if(board[i][j] == '$' || !curr->child[index])
            return;
        
        curr = curr->child[index];
         
        if(curr->wordEnd > 0) {
            ans.push_back(curr->word);
            curr->wordEnd -= 1;
        }
        
        char ch = board[i][j];
        board[i][j] = '$';
        
        if(i > 0) findWordsRec(board, i-1, j, n, m, ans, curr);
        if(i < n-1) findWordsRec(board, i+1, j, n, m, ans, curr);
        if(j > 0) findWordsRec(board, i, j-1, n, m, ans, curr);
        if(j < m-1) findWordsRec(board, i, j+1, n, m, ans, curr);
        
        board[i][j] = ch;
    }
};