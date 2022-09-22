class Solution {
    vector<vector<int>> next = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                    break;
                }
            }
            
            if(!q.empty()) break;
        }
        
        int ans = -1;
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            
            while(sz--) {
                int row = q.front().first;
                int col = q.front().second;
                
                q.pop();
                
                for(int k=0; k<4; k++) {
                    int i = row + next[k][0];
                    int j = col + next[k][1];
                    
                    if(i>=0 && i<m && j>=0 && j<n && !visited[i][j]) {
                        if(grid[i][j] == 1) return ans;
                        
                        else {
                            q.push({i, j});
                            visited[i][j] = true;
                        }
                    }
                }
            } 
        }
        
        return 0;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        
        if(isEdge(grid, row, col)) q.push({row, col});
        
        visited[row][col] = true;
        
        for(int k=0; k<4; k++) {
            int i = row + next[k][0];
            int j = col + next[k][1];
            
            if(i>=0 && j>=0 && i<m && j<n && grid[i][j] == 1 && !visited[i][j])
                dfs(    grid, visited, i, j);
        }
    }
    
    bool isEdge(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        
        for(int k=0; k<4; k++) {
            int i = row + next[k][0];
            int j = col + next[k][1];
             
            if(i>=0 && j>=0 && i<m && j<n && grid[i][j] == 0)
                 return true;
        }
        
        return false;
    }
};