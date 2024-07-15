class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeStringRec(s, i);
    }
    
    string decodeStringRec(string& s, int& i){
        string ans;
        
        while(i < s.length() && s[i] != ']'){
            if(isdigit(s[i])){
                int k = 0;
                
                while(i<s.length() && isdigit(s[i])) 
                    k = (10 * k) + s[i++] - '0';
                
                i++;
                
                string r = decodeStringRec(s, i);
                
                while(k--) ans += r;
                 
                i++;
            }
            
            else ans += s[i++];
        }
        
        return ans;
    }
};