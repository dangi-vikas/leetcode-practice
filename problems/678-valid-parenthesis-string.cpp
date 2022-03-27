class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int i=0, open=0, close=0;
        
        while(i < n) {
            if(s[i] == '(' || s[i] == '*')
                open++;
            else close++;
            
            if(open < close)
                return false;
            
            i++;
        }
          
        i = n-1, open = 0, close = 0;
        while(i >= 0) {
            if(s[i] == ')' || s[i] == '*')
                close++;
            else open++;
            
            if(open > close)
                return false;
            
            i--;
        }
        
        return true;
    }
};