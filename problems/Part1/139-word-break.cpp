class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        
        return wordBreakRec(0, memo, s, word);
    }

    bool wordBreakRec(int index, vector<int>& memo, string& s, unordered_set<string>& word){
        
        if(index == s.size()) return true;
        if(memo[index] != -1) return memo[index] == 0 ? false : true;
        
        string container = "";
        for(int i = index; i<s.size(); i++){
            container.push_back(s[i]);
            if(word.count(container) && wordBreakRec(i+1, memo, s, word)){
                memo[index] = 1;
                return true;
            }
        }
        
        memo[index] = 0;
        return false;
    }
};