class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int idx = s.length();
        vector<int> curr(idx);
         
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == c){
                idx = i;
                curr[i] = 0;
            }
            
            else curr[i] = idx == s.length() ? s.length() : idx-i;
        }
        
        idx = -1;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == c) {
                idx = i;
                curr[i] = min(0, curr[i]);
            }
            
            else curr[i] = min(idx == -1 ? curr[i] : i-idx, curr[i]);
        }
        
        return curr;
    }
};