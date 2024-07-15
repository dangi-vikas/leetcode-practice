class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int m = (sum + target) / 2;
        
        if(((sum + target) % 2) || m < 0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0; i<n+1; i++) dp[i][0] = 1;
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][m];
    }
};