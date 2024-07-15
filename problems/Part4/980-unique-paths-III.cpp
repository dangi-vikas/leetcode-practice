class Solution {
    int startX, startY, emptySqrs = 1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) { 
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) emptySqrs++;
                if(grid[i][j] == 1) startX = i, startY = j;
            }
        }
            
        return findWays(startX, startY, 0, visited, grid);
    }
       
    int findWays(int r, int c, int blocks, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        if(grid[r][c] == 2) {
            if(blocks == emptySqrs) return 1;
            return 0;
        }
        
        int ways = 0;
        visited[r][c] = 1; 

        for(int d=0; d<4; d++) {
            int x = r + dx[d];
            int y = c + dy[d];

            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && !visited[x][y] && grid[x][y] != -1) 
                ways += findWays(x, y, blocks + 1, visited, grid);
        }
        
        visited[r][c] = 0; 
        
        return ways;
    }
};