class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> wordCounts;
        
        for(auto word : words) wordCounts[word]++;
        
        int wordLength = words[0].length();
        int totalWords = words.size();
        
        int size = wordLength * totalWords;
        if(s.length() < size) return ans;
        
        for(int i=0; i<=s.length()-size; i++) {
            if(wordCounts[s.substr(i, wordLength)] > 0) {
                unordered_map<string, int> tempCounts = wordCounts;
                int count = 1;
                tempCounts[s.substr(i, wordLength)]--;
                
                for(int j=i+wordLength; j<=s.length()-wordLength; j+=wordLength) {
                    if(tempCounts[s.substr(j, wordLength)] > 0) {
                        count++;
                        tempCounts[s.substr(j, wordLength)]--;
                    }
                    
                    else break;
                }
                
                if(count == totalWords) ans.emplace_back(i);
            }
        }
        
        return ans;
    }
};