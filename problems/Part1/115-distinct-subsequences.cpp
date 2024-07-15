class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<double> dp(m+1, 0);
        
        for(int i=0; i<n+1; i++) dp[0] = 1;
        
        for(int i=1; i<n+1; i++) {
            for(int j=m; j>=1; j--) {
                if(s[i-1] == t[j-1]) 
                    dp[j] = dp[j-1] + dp[j];
            }
        }
        
        return (int) dp[m];
    }
};