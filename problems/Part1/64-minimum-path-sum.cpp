class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //initialised dp matrix of mxn
        vector<vector<int>> dp(m, vector<int>(n));

        //fillling dp with path sums after traversing grid
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){

                //for the first element 
                if(i==0 && j==0) dp[i][j] = grid[i][j];

                else
                dp[i][j] = grid[i][j] + min(i==0?INT_MAX:dp[i-1][j], j==0?INT_MAX:dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
    }
};