class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k + maxPts, 0);
        
        for(int i=k; i<=min(k+maxPts-1, n); i++) 
            dp[i] = 1;
        
        double sum = min(n - k + 1, maxPts); 
        
        for(int i=k-1; i>=0; i--) {
            dp[i] = sum * (1 / (float) maxPts);
            sum = sum - dp[i + maxPts] + dp[i]; 
        }
        
        return dp[0];
    }
};