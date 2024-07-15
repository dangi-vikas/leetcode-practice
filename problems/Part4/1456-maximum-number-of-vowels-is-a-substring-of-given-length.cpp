class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = 0;
        int currCount = 0, maxCount = 0;
        
        while(j < s.length()) {
            if(j - i < k) {
                if(isVowel(s[j])) currCount++;
                j++;
            }
            
            else {
                if(isVowel(s[j]) && !isVowel(s[i])) currCount++;
                if(!isVowel(s[j]) && isVowel(s[i])) currCount--;
                
                i++;
                j++;
            }
            
            maxCount = max(maxCount, currCount);
        }    
        
        return maxCount;
    }
    
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};
