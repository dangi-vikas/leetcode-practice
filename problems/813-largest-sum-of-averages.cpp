class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n+1, vector<double>(k+1, 0));
        
        for(int i=0; i<=k; i++) dp[n][i] = 0;
        for(int i=0; i<n; i++) dp[i][0] = INT_MIN;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<=k; j++) {
                double sum = 0.0, val = 0.0;
                
                for(int l=i; l<n; l++) {
                    sum += nums[l];
                    double avg = sum / (l - i + 1);
                    val = max(val, avg + dp[l+1][j-1]);
                }
                
                dp[i][j] = val; 
            }
        }
        
        return dp[0][k];
    }
};