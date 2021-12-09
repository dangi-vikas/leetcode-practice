class Solution {
public:
    string reverseVowels(string s) {
        int i = 0 , j = s.length()-1 ; 
        
        while(i < j){
            while(i<j && !isvowel(s[i]) ) i++;
            while(i<j && !isvowel(s[j]) ) j--;
            
            if(isvowel(s[i]) && isvowel(s[j]))
                swap(s[i], s[j]);
            
            i++; j--;
        }
        
        return s;
    }
    
     bool isvowel( char c ){
        if(c >= 'A' && c <= 'Z')
            c = c-'A' + 'a'; 
            
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true; 

        return false;
    }
};