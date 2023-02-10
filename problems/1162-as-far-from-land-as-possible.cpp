class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited = grid;
        int dist = -1;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++) 
                if(visited[i][j] == 1)
                    q.push({i, j});

        if(q.empty() || (q.size() == n*n)) 
            return -1;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int d=0; d<4; d++) {
                    int x = r + dx[d];
                    int y = c + dy[d];

                    if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0) {
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }

            dist++;
        }

        return dist;
    }
};