class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return canWin(n, dp);
    }
    
    bool canWin(int n, vector<int>& dp) {
        if(n <= 1) return false;
        if(dp[n] != -1) return dp[n];
        
        dp[n] = 0;
        
        for(int i=1; i<=sqrt(n); i++) 
            if(n%i == 0) dp[n] |= !canWin(n-i, dp);
        
        return dp[n];
    }
};