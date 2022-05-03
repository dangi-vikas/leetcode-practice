class Solution {
public:
    double soupServings(int n) {
        vector<vector<double>> dp(200, vector<double>(200, 0));
        
        if(n > 4800) return 1.0; 
        
        return soupServingsRec((n + 24) / 25, (n + 24) / 25, dp);
    }
    
    double soupServingsRec(int a, int b, vector<vector<double>>& dp) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        if(dp[a][b] > 0.0) return dp[a][b];
        
        dp[a][b] = 0.25 * (soupServingsRec(a - 4, b, dp)
                         + soupServingsRec(a - 3, b - 1, dp)
                         + soupServingsRec(a - 2, b - 2, dp)
                         + soupServingsRec(a - 1, b - 3, dp));
        
        return dp[a][b];
    }
};