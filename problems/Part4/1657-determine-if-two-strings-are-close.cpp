class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        
        unordered_map<char, pair<int, int>> wordMap;
        vector<int> wordArr1, wordArr2;
        
        for(int i=0; i<word1.length(); i++) {
            wordMap[word1[i]].first++;
            wordMap[word2[i]].second++;
        }
        
        for(auto it=wordMap.begin(); it!=wordMap.end(); it++) {
            if(it->second.first == 0 || it->second.second == 0)
                return false;
            
            wordArr1.push_back(it->second.first);
            wordArr2.push_back(it->second.second);
        }
        
        sort(wordArr1.begin(), wordArr1.end());
        sort(wordArr2.begin(), wordArr2.end());
        
        return (wordArr1 == wordArr2);
    }
};
