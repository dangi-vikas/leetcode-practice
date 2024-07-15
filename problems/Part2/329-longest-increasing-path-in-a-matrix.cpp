class Solution {
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, dfs(matrix, m, n, i, j, dp));
            }
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& matrix, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i == n || j == m) return 0;
        if(dp[i][j] > 0) return dp[i][j];
        
        int mx = 0;

        for(vector<int> dir : dirs) {
            int x = i + dir[0], y = j + dir[1];

            if(x<n && y<m && x>=0 && y>=0 && matrix[x][y] > matrix[i][j])
                mx = max(mx, dfs(matrix, m, n, x, y, dp));
        }
        
        dp[i][j] = mx+1;
        return mx+1;
    }
};