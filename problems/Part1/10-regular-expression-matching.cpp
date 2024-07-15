class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m+1,0);;
        
        prev[0] = true;
        
        for(int i=1; i<=m; i++) {
            if(p[i-1] == '*') 
                prev[i] = prev[i-2]; 
        }
        
        for(int i=1; i<=n; i++) {
            vector<bool> curr(m+1, false);
            
            for(int j=1; j<=m; j++) {
                if(p[j-1] == s[i-1] | p[j-1] == '.')
                    curr[j] = prev[j-1];
                
                else if(p[j-1] == '*') {
                    curr[j] = curr[j-2];  
                    if(s[i-1] == p[j-2] | p[j-2] == '.')
                        curr[j] = prev[j] | curr[j];  
                }
            }
            
            prev = curr;
        }
        
        return prev[m];
    }
};