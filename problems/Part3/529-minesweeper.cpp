class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.empty()) return board;
        
        int x=click[0], y=click[1];
        
        if(board[x][y] == 'M')
            board[x][y] = 'X';
        else {
            int mineCount = dfs(board, x, y);
            if(mineCount) board[x][y] = mineCount + '0';
            else {
                board[x][y] = 'B';
                
                for(int i=x-1; i<x+2; i++) {
                    for(int j=y-1; j<y+2; j++) {
                        if((i>=0 && i<board.size() && j>=0 && j<board[i].size()) && (board[i][j] != 'B')){
                            vector<int> v = {i,j};
                            updateBoard(board, v);
                        } 
                            
                    }
                }
            }
        }
        
        return board;
    }
    
    int dfs(vector<vector<char>>& board, int& x, int& y) {
        int mineCount = 0;
        
        for(int i=x-1; i<x+2; i++) {
            for(int j=y-1; j<y+2; j++) {
                if((i>=0 && i<board.size() && j>=0 && j<board[i].size()) && (board[i][j] == 'M')) 
                    mineCount++;
            }
        }
        
        return mineCount;
    }
};