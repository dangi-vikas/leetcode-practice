class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word : words) {
            string revWord = word; 
            reverse(revWord.begin(), revWord.end());  
            
            if(revWord == word) return revWord;
        }
        
        return "";
    }
};
