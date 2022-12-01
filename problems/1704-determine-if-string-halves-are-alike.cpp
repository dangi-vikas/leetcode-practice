class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int count = 0;
        
        for(int i=0; i<n; i++) {
            if(i < n/2 && isVowel(s[i])) count++; 
            else if(isVowel(s[i])) count--;
        } 
        
        return count == 0;
    }
    
    bool isVowel(char ch) {
        if(isupper(ch)) ch += 32;
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};