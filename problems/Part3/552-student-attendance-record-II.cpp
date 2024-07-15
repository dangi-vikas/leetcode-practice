class Solution {
    const long long mod = 1e9 + 7;
    
public:
    int checkRecord(int n) {
        vector<vector<int>> dp(3, vector<int>(2));
        
        dp[0][0] = dp[0][1] = dp[1][0] = 1;
        
        for(int i=1; i<n; i++) {
            vector<vector<int>> newdp(3, vector<int>(2));
            
            newdp[0][0] = (dp[0][0] % mod + dp[1][0] % mod + dp[2][0] % mod) % mod;
            newdp[1][0] = dp[0][0] % mod;
            newdp[2][0] = dp[1][0] % mod;
            newdp[0][1] = (dp[0][0] % mod + dp[1][0] % mod + dp[2][0] % mod + 
                           dp[0][1] % mod + dp[1][1] % mod + dp[2][1] % mod) % mod;
            newdp[1][1] = dp[0][1] % mod;
            newdp[2][1] = dp[1][1] % mod;
            
            for(int i=0; i<3; i++) {
                for(int j=0; j<2; j++) {
                    dp[i][j] = newdp[i][j];
                }
            }
        }
        
        long long ans = 0;
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<2; j++) {
                ans = (ans % mod + dp[i][j] % mod) % mod;
            }
        }
        
        return ans % mod;
    }
};
