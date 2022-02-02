class Solution {
public:
    bool detectCapitalUse(string word) {
        for (int i = 1; i < word.size(); i++){
            if (islower(word[i-1]) && isupper(word[i])) return false;
            else if (isupper(word[i-1]) && islower(word[i]) && i!=1) return false;
        } 
            
        return true;
    }
};