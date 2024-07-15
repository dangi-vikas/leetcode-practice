class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        
        while(i < s.length()) {
            if(abs(s[i+1] - s[i]) == 32) {
                s.erase(i, 2);
                i = 0;
            }  
            
            else i++;
        }
            
        return s;
    }       
};