class Solution {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if(board[i][j] == word[0] && dfs(board, word, n, m, i, j, 0))
                    return true;
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int n, int m, int row, int col, int index) {
        if(index == word.length()-1) 
            return true;
        
        char temp = board[row][col];
        board[row][col] = '$';
        
        for(int d=0; d<4; d++) {
            int x = row + dx[d];
            int y = col + dy[d];
            
            if(x >= 0 && y >= 0 && x < n && y < m && board[x][y] == word[index+1])
                if(dfs(board, word, n, m, x, y, index+1)) return true;
        }
        
        board[row][col] = temp;
        
        return false; 
    }
};