class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length(); 
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        
        for(int i=m-1; i>=0; i--) dp[i][n] = dp[i+1][n] + s1[i];
        for(int i=n-1; i>=0; i--) dp[m][i] = dp[m][i+1] + s2[i];
        
        for(int i=m-1; i>=0; i--) {
            char ch = s1[i];
            
            for(int j=n-1; j>=0; j--) {
                if(ch == s2[j]) 
                    dp[i][j] = dp[i + 1][j + 1];
                else 
                    dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
            }
        }
        
        return dp[0][0];
    }
};