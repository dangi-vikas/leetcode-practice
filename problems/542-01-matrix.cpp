class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(mat[row][col] == 0) {
                    dp[row][col] = 0;
                    continue;
                }
                
                if(row > 0 && dp[row - 1][col] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row - 1][col] + 1);
                }
                
                if(col > 0 && dp[row][col - 1] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row][col - 1] + 1);
                }
            }
        }
        
        for(int row = n - 1; row >= 0; row--) {
            for(int col = m - 1; col >= 0; col--) {
                if(mat[row][col] == 0) {
                    dp[row][col] = 0;
                    continue;
                }
                
                if(row < n - 1 && dp[row + 1][col] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row + 1][col] + 1);
                }
                
                if(col < m - 1 && dp[row][col + 1] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row][col + 1] + 1);
                }
            }
        }
        
        return dp;
    }
};