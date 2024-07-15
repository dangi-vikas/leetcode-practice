class Solution {
    int mod = 1e9 + 7;

public:
    int numTilings(int n) {
        vector<int> dp(n+1);

        if(n < 3) return n;

        dp[0] = 1; dp[1] = 1; dp[2] = 2;

        for(int i=3; i<=n; i++) 
            dp[i] = ((2 * dp[i-1]) % mod + dp[i-3]) % mod;

        return dp[n];
    }
};