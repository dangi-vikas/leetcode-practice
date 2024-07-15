class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;

        for(; i<word1.size() && j<word2.size(); i+=2, j++) 
                word1.insert(i+1, string(1, word2[j]));

        if(j < word2.size()) word1 += word2.substr(j);

        return word1;
    }
};