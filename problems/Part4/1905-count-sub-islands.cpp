class Solution {
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1 && grid1[i][j] == 1) {
                    grid2[i][j] = 0;
                    if(dfs(grid1, grid2, i, j, m, n)) count++;
                }
            }
        }

        return count;
    }

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int m, int n) {
        for(int i=0; i<4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];

            if(x == -1 || y == -1 || x == m || y == n || grid2[x][y] == 0) continue;

            if(grid2[x][y] == -1) {
                grid2[r][c] = -1;
                return false;
            }

            if(grid1[x][y] == 0) {
                grid2[x][y] = -1;
                grid2[r][c] = -1;
                return false;
            }

            grid2[x][y] = 0;

            if(!dfs(grid1, grid2, x, y, m, n)) {
                grid2[r][c] = -1;
                grid2[x][y] = -1;
                return false;
            }
        }

        return true;
    }
};class Solution {
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1 && grid1[i][j] == 1) {
                    grid2[i][j] = 0;
                    if(dfs(grid1, grid2, i, j, m, n)) count++;
                }
            }
        }

        return count;
    }

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int m, int n) {
        for(int i=0; i<4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];

            if(x == -1 || y == -1 || x == m || y == n || grid2[x][y] == 0) continue;

            if(grid2[x][y] == -1) {
                grid2[r][c] = -1;
                return false;
            }

            if(grid1[x][y] == 0) {
                grid2[x][y] = -1;
                grid2[r][c] = -1;
                return false;
            }

            grid2[x][y] = 0;

            if(!dfs(grid1, grid2, x, y, m, n)) {
                grid2[r][c] = -1;
                grid2[x][y] = -1;
                return false;
            }
        }

        return true;
    }
};