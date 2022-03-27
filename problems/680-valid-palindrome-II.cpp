class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        
        while (i < j && s[i] == s[j]) {
            i++; j--;
        }
        
        string tmp1 = s, tmp2 = s;
        string a = tmp1.erase(i, 1);
        string b = tmp2.erase(j, 1);
        
        if (!isPalindrome(a) && !isPalindrome(b))
            return false;
        
        return true;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        
        while (i < j) 
            if (s[i++] != s[j--])
                return false;
        
        return true;
    }   
};