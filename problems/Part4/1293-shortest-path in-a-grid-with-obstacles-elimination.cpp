class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        if(n == 1 && m == 1) return 0;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        map<pair<int, int>, int> visited;
        queue<pair<pair<int, int>, pair<int, int>>> q; 
        
        q.push({{0, 0}, {k, 0}});
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                visited[{i, j}] = -1;
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            
            for(int i=0; i<4; i++) {
                int x = t.first.first + dx[i]; 
                int y = t.first.second + dy[i];
                int nextK = t.second.first;
                
                if(x == n-1 && y == m-1)
                    return t.second.second + 1;
                
                if(x < 0 || x >= n || y < 0 || y >= m) continue; 
                if(grid[x][y] == 1 && t.second.first == 0) continue;
                if(grid[x][y]) nextK--;
                if(visited[{x, y}] != -1 && visited[{x, y}] >= nextK) continue;
                
                visited[{x, y}] = nextK;
                q.push({{x, y}, {nextK, t.second.second + 1}});
            }
        }
        
        return -1;
    }
};