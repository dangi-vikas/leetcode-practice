class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuRec(board);
    }
    
    bool solveSudokuRec(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.') {
                    for(char k='1'; k<='9'; k++) {
                        if(isValid(board, i, j, k)){
                            board[i][j] = k;
                            
                            if(solveSudokuRec(board)) return true;
                            
                            board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int& row, int& column, char& n) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == n) return false;
            if(board[i][column] == n) return false;
            if(board[3*(row/3) + (i/3)][3*(column/3) + (i%3)] == n) return false;
        }
        
        return true;
    }
};