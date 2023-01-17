class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int oneCount = 0, zeroToOnes = 0;
        int i = 0;
        
        while(i<s.length() && s[i] == '0') i++;
        
        for(; i<s.length(); i++) {
            if(s[i] == '0') zeroToOnes++;
            else oneCount++;
            
            if(zeroToOnes > oneCount) 
                zeroToOnes =  oneCount;
        }
        
        return zeroToOnes;
    } 
};