class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        
        for(char ch : letters) count[ch - 'a']++;
        
        return dfs(words, score, count, 0);
    }
    
    int dfs(vector<string>& words, vector<int>& score, vector<int>& count, int i) {
        if(i == words.size()) return 0;
        
        int skip = dfs(words, score, count, i+1);
        int scores = 0;
        
        bool isValid = true;
        
        for(char ch : words[i]) {
            if (--count[ch - 'a'] < 0) isValid = false;
            scores += score[ch - 'a'];
        }
        
        int take = isValid ? scores + dfs(words, score, count, i+1) : 0;
        
        for(char ch : words[i]) count[ch - 'a']++;
        
        return max(skip, take);
    }
};
