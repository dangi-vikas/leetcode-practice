class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), steps = 0;
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        
        q.push(1);
        visited[n-1][0] = true;
        
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                int cell = q.front();
                q.pop();

                if(cell == n*n) return steps;
                
                for(int j=1; j<=6; j++) {
                    if(j + cell > n*n) break;
                    
                    pair<int, int> pos = findCoordinates(j + cell, n);
                    int r = pos.first, c = pos.second;
                    
                    if(visited[r][c] == true) continue;
                    visited[r][c] = true;
                    
                    if(board[r][c] == -1) q.push(j + cell);
                    else q.push(board[r][c]);
                }
            }
            
            steps++;
        }
        
        return -1;
    }
    
    pair<int, int> findCoordinates(int currCell, int n) {
        int r = n - (currCell - 1) / n - 1;
        int c = (currCell - 1) % n;
        
        if(r % 2 == n % 2) return {r, n-c-1};
        
        return {r, c};
    }
};