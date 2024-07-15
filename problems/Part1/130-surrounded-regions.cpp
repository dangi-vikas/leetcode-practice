class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        
        int m=board.size(), n=board[0].size();
        
        //catching boundary Os and their connencted Os

        //first and last rows
        for(int i=0; i<m; i++){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        
        //first and last column
        for(int j=1; j<n-1; j++){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        
        //modifying board by changing completely sorrounded Os to X
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O') board[i][j] ='X';
                else if(board[i][j]=='1') board[i][j] ='O';
            }
        }
    }
    
    //DFS
    void dfs(vector<vector<char>> &board, int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            
            if(i+1 < board.size()) dfs(board, i+1, j);
            if(i > 1) dfs(board, i-1, j);
            if(j+1 < board[i].size()) dfs(board, i, j+1);
            if(j > 1) dfs(board, i, j-1);
        }
    }
};