    class Solution {
public:
    bool isNumber(string s) {
        bool foundDigit = false, foundPeriod = false; 
        bool foundE = false, checkSign = true; 
        
        for (char c : s) {
            if (checkSign and (c == '-' or c == '+')) {
                checkSign = false;
                continue;
            }
            
            checkSign = false;
            
            if (c == '.') {
                if (not foundE and not foundPeriod) 
                    foundPeriod = true;
                
                else return false;
                
                continue;
            }
            
            if (c == 'e' or c == 'E') {
                if(not foundE and foundDigit) foundE = true;
                else return false;
                
                checkSign = true;
                foundDigit = false;
                
                continue;
            }
            
            if (c - '0' >= 0 and c - '0' <= 9) {
                foundDigit = true;
                continue;
            }
            
            return false;
        }
        
        return foundDigit;
    }
};