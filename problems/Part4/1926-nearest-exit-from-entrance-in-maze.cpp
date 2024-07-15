class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        
        while(!q.empty()) {
            auto temp = q.front(); 
            q.pop();
            
            int x = temp[0], y = temp[1], steps = temp[2];
            
            if(maze[x][y] == '+') continue;
            maze[x][y] = '+';
            
            if(x == n-1 || y == m-1 || x == 0 || y == 0) 
                if(x != entrance[0] || y != entrance[1])
                    return steps;
            
            steps++;
            
            for(int d=0; d<4; d++) {
                int X = x + dx[d];
                int Y = y + dy[d];
                
                if(X >= 0 && Y >= 0 && X < n && Y < m && maze[X][Y] == '.')
                    q.push({X, Y, steps});
            }
            
        }
        
        return -1;
    }
};