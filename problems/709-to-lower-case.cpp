class Solution {
public:
    string toLowerCase(string s) {
        int i=0, j=s.length();
        
        while(i<=j) {
            if((int)s[i] >= 65 && (int)s[i] <=  90)
                s[i] = (char)((int) s[i] + 32);
                
            if((int)s[j] >= 65 && (int)s[j] <=  90)
                s[j] = (char)((int) s[j] + 32);
                
            i++; j--;
        }
                                         
        return s;
    }
};