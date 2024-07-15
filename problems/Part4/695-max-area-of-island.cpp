class Solution {
    vector<int> di= {-1, 0, 1, 0};
    vector<int> dj = {0, -1, 0, 1};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
            
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    ans = max(ans, findAreaOfIsland(grid, visited, i, j));
                }
            }
        }
        
        return ans;
    }
    
    int findAreaOfIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        int ans=0;
        
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(visited[i][j] || grid[i][j]==0) return 0;
        
        visited[i][j] = true;
        
        for(int k=0; k<4; k++)
            ans += findAreaOfIsland(grid, visited, i+di[k], j+dj[k]);
        
        return ans + 1;
    }
};