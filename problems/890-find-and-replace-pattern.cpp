class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(string word : words) 
            if(match(word, pattern))
                ans.push_back(word);
        
        return ans;
    }
    
    bool match(string& word, string& pattern) {
        vector<char> patternToWord(26, 0), wordToPattern(26, 0);
        
        for(int index=0; index<word.length(); index++) {
            if(patternToWord[pattern[index] - 'a'] == 0)
                patternToWord[pattern[index] - 'a'] = word[index];
        
            if(wordToPattern[word[index] - 'a'] == 0)
                wordToPattern[word[index] - 'a'] = pattern[index];
            
            if((patternToWord[pattern[index]-'a'] != word[index]) || (wordToPattern[word[index]-'a'] != pattern[index]))
                return false;
        }
        
        return true;
    }
};