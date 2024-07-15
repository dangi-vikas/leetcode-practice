class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //if the first position contains obstacle 
        if(obstacleGrid[0][0] == '1') return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        //initialising a dp matrix with 0
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //filling the first row of dp till with 1 till an obstacle is encountered 
        for(int i=0; i<dp[0].size(); i++){
            if(obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }
        
        //filling the first column of dp till with 1 till an obstacle is encountered 
        for(int i=0; i<dp.size(); i++){
            if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }
        
        //filling the dp with possible paths for every position
        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[i].size(); j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};