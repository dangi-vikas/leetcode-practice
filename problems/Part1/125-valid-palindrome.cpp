class Solution {
public:
    bool isPalindrome(string s) {
       int l=0, r=s.size() -1;
        
        while(l<=r){

            //if one of the starting characters is not alphanumeric
            if(!isalnum(s[l])){
                l++; continue;                              //skip
            }
            
            //if one of the ending characters is not alphanumeric
            if(!isalnum(s[r])){
                r--; continue;                              //skip
            }
            
            /*if the valid ith charcter from the beginning does not match 
            to the valid ith from the end*/
            if(tolower(s[l++]) != tolower(s[r--])) return false;
        }
        
        return true;
    }
};