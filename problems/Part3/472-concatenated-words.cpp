class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> wordSet;

        if(words.size() == 0) return ans;
        
        for(string word : words)
            wordSet.insert(word);

        for(string word : words) 
            if(isConcat(word, wordSet)) ans.push_back(word);
        
        return ans;
    }

    bool isConcat(string& word, unordered_set<string>& wordSet) {
        int n = word.length();

        for(int i=1; i<n; i++) {
            string suffix = word.substr(i);
            if(wordSet.find(word.substr(0, i)) != wordSet.end() && 
               (wordSet.find(suffix) != wordSet.end() || isConcat(suffix, wordSet))) {
                   wordSet.insert(suffix);
                   return true;
               }
        }

        return false;
    }
};