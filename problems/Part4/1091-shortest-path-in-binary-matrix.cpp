class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<int> dx = {-1, 0, 1, 0, 1, 1, -1, -1};
        vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};

        if(!grid[0][0]) {
            q.push({0, 0});
            dist[0][0] = 1;
        }

        else return -1;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();
            
            for(int d=0; d<8; d++) {
                int x = r + dx[d];
                int y = c + dy[d];

                if(x >= 0 && y >= 0 && x < n && y < n && !grid[x][y] && dist[x][y] == -1) {
                    dist[x][y] = dist[r][c] + 1;
                    q.push({x, y});
                }
            }
        }

        return (dist[n-1][n-1] != -1) ? dist[n-1][n-1] : -1;
    }
};