class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m+1, 0);
        
        for(int i=1; i<=p.size(); i++){
            if(p[i-1] == '*') prev[i] = true;
            else break;
        }
        
        prev[0] = true;
        
        for(int i=1; i<n+1; i++){
            vector<bool> curr(m+1, 0);
            
            for(int j=1; j<m+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    curr[j] = prev[j-1];

                else if(p[j-1] == '*')
                    curr[j] = prev[j] | curr[j-1];
            }
            
            prev = curr;
        }
        
        return prev[m];
    }
};s