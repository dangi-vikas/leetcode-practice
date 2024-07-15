class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int i : nums) sum += i;
        
        if(sum % 2) return false;
        
        return canPartitionRec(nums, sum/2);
    }
    
    bool canPartitionRec(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp((n+1), vector<bool>(sum+1, false));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) dp[i][j] = false;
                else if(j==0) dp[i][j] = true;
                
                else if(nums[i-1] <= j )
                    dp[i][j] = ((dp[i-1][j - nums[i-1]]) || dp[i-1][j]);
                
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};