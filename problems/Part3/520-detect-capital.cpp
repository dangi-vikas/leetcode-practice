class Solution {
public:
    bool detectCapitalUse(string word) {

        for(int i=0; i<word.length(); i++) {
            if(islower(word[0]) && isupper(word[i])) return false;
            if(i > 1 && isupper(word[0]) && islower(word[1]) && isupper(word[i])) return false;
            if(i > 1 &&isupper(word[0]) && isupper(word[1]) && islower(word[i])) return false;
        }

        return true;
    }
};