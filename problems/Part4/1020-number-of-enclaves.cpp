class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0 || i==n-1 || j==m-1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int d=0; d<4; d++) {
                int x = row + dx[d];
                int y = col + dy[d];

                if(x>=0 && y>=0 && x<n && y<m && !visited[x][y] && grid[x][y] == 1) {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }

        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if(!visited[i][j] & grid[i][j] == 1) ans++;
    

        return ans;
    }
};