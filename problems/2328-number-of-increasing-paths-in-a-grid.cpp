class Solution {
    typedef long long ll;
    int mod = 1e9 + 7;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        ll countPath = 0;
        
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                countPath += countPaths(grid, dp, i, j, m, n);
        
        return countPath % mod;
    }

    int countPaths(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c, int m, int n) {
        ll countPath = 1;
        
        if (dp[r][c] != -1) return dp[r][c];
        
        for(int d=0; d<4; d++) {
            int x = r + dx[d];
            int y = c + dy[d];
            
            if (x >= 0 && x < m && y >= 0 && y < n && grid[r][c] < grid[x][y]) 
                countPath += countPaths(grid, dp, x, y, m, n);
        }

        return dp[r][c] = countPath % mod;
    }
};