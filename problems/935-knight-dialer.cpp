class Solution {
    const int mod = 1000000007;
    
public:
    int knightDialer(int n) {
        vector<vector<int>> paths = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        vector<vector<long>> dp(n+1, vector<long>(10, 0));
        
        for(int i=0; i<10; i++) dp[1][i] = 1;
        
        for(int i=2; i<=n; i++) {
            for(int j=0; j<10; j++) {
                for(auto num : paths[j]) {
                    dp[i][j] += dp[i-1][num];
                }
                
                dp[i][j] %= mod;
            }
        }
        
        long ans = 0;
        
        for(int i=0; i<10; i++) ans += dp[n][i];
        
        return ans % mod;
    }
};