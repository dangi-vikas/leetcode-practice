class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=m-1; i>=0; i--) {
            for(int j1=n-1; j1>=0; j1--) {
                for(int j2=n-1; j2>=0; j2--) {
                    if(i == m-1)
                        dp[i][j1][j2] = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    
                    else {
                        int mx = 0;

                        for(int p=-1; p<=1; p++) {
                            for(int q=-1; q<=1; q++)
                                if(j1 + p >= 0 && j1 + p < n && j2 + q >= 0 && j2 + q < n)
                                    mx = max(mx, dp[i+1][j1+p][j2+q]);
                        }

                        dp[i][j1][j2] = mx + ((j1==j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
                    }
                }
            }
        }

        return dp[0][0][n-1];
    }
};
