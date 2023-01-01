class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size() != (count(s.begin(), s.end(), ' ') + 1))
            return false;
        
        unordered_map<char, string> bijection;
        unordered_map<string, int> wordCount;
        
        istringstream ss(s);
        string word;
        
        for(auto ch : pattern){
            ss >> word;
            
            if((bijection[ch] == "" && wordCount[word] == 0) || bijection[ch] == word){
                bijection[ch] = word;
                wordCount[word] = ch;
            }
            
            else return false;
        }
        
        return true;
    }
};