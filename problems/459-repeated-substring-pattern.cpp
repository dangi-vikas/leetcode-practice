class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> lps(n);
        
        KMP(s, lps);
        
        return lps[n-1] != 0 && n % (n - lps[n-1]) == 0;
    } 
    
    void KMP(string &s, vector<int>&lps) {
        lps[0] = 0;
        int i = 0, j = 1;
        
        while(j < s.length()) {
            if(s[i] == s[j]) {
                lps[j] = (i) + 1;
                i++; j++;
            }
            
            else {
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                }
                
                else i = lps[i-1];
            }
        }
    }
};