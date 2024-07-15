class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1 ; 
        
        while(i < j){
            while(i<j && !isVowel(s[i])) i++;
            while(i<j && !isVowel(s[j])) j--;
            
            if(isVowel(s[i]) && isVowel(s[j]))
                swap(s[i], s[j]);
            
            i++; j--;
        }
        
        return s;
    }
    
    bool isVowel(char ch) {
        if(ch >= 'A' && ch <= 'Z')
            ch += 32;
        
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    } 
};