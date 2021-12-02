xclass Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int d[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        
        int m=board.size(), n=board[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int t = board[i][j];
                int live=0;
                
                for(int k = 0; k < 8; k++){
                    int x = d[k][0] + i;
                    int y = d[k][1] + j;
                     
                    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                        continue;
                     
                    if(board[x][y]==1 || board[x][y]==-1) live++;
                }
                
                if(t==1) {
                    if(live<2) board[i][j] = -1;
                    else if(live>3) board[i][j] = -1;
                }
                
                else
                    if(live==3) board[i][j] = 2;
        
                
            }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                 board[i][j] = board[i][j] > 0 ? 1 : 0;
        
    }
};