class Solution {
    int dp[21][21];
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        int player1 = PredictTheWinnerRec(0, nums.size()-1, nums); 
        
        int sum = 0;
        for(int num : nums) sum += num;
         
        int player2 = sum - player1; 
        
        if(player1 >= player2) return true;
        return false;
    }
    
    int PredictTheWinnerRec(int i,int j,vector<int>& nums){
        if(i == j) return nums[i]; 
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int choice1 = nums[i] + min(PredictTheWinnerRec(i+1, j-1, nums), PredictTheWinnerRec(i+2, j, nums));
        int choice2 = nums[j] + min(PredictTheWinnerRec(i+1, j-1, nums), PredictTheWinnerRec(i, j-2, nums));
        
        dp[i][j] = max(choice1, choice2);
        
        return dp[i][j];
    }
};