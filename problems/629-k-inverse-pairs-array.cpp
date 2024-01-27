class Solution { 
    const static int mod = 1e9 + 7, N = 1010;
    int dp[N][N] = {};
    
public:
    int kInversePairs(int n, int k) {
        dp[0][0] = 1;

        for(int i=1; i<=n; i++) {
            long long s = 0; 
                
            for(int j=0; j<=k; j++) {
                s += dp[i-1][j];

                if(j >= i) s -= dp[i-1][j-i];
                
                dp[i][j] = ((long long) dp[i][j] + s) % mod; 
            }
        }
        
        return dp[n][k];
    }
};
