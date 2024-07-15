class Solution {  
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> wordCount;
        
        for(string word : words) {
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            
            if(wordCount[revWord] > 0) {
                ans += 4;
                wordCount[revWord]--;
            }
            
            else wordCount[word]++;
        }
        
        for(auto word : wordCount) 
            if(word.first[0] == word.first[1] && word.second > 0)
                return ans += 2;
        
        return ans;
    }
};