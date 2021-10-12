class Solution {
public:
    int lengthOfLastWord(string s) {
        string r = s;

        //Removing trailing spaces (if any)
        while(*(r.end()-1) == ' ') r.pop_back();
        
        //Reverse of input string        
        reverse(r.begin(), r.end());  
        
        //iterator to the first space ' ' in reverse string
        auto it = find(r.begin(), r.end(), ' ');

         //length of first word in reverse string = length of last word in original string    
        int len = it - r.begin();      

        return len;
    }
};