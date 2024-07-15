class Solution {
public:
 
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_map<string, int> longestChainLength;
        int maxChainLength = -1;

        for(auto& word: words) {
            longestChainLength[word] = 1;

            for(int i=0; i<word.size(); i++){
                string reducedWord = word.substr(0, i) + word.substr(i+1) ;

                if(longestChainLength.find(reducedWord) != longestChainLength.end())
                    longestChainLength[word] = max(longestChainLength[word], 
                                                   longestChainLength[reducedWord] + 1) ;
            }

            maxChainLength = max(maxChainLength, longestChainLength[word]) ;
        }

        return maxChainLength;
    }
};
