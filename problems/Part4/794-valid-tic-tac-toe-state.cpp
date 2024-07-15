class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countO = 0, countX = 0;
        
        for(int x=0; x<3; x++) {
            for(int y=0; y<3; y++) {
                if(board[x][y] == 'O') countO++;
                else if(board[x][y] == 'X') countX++;                
            }
        }  
        
        char a1 = board[0][0], a2 = board[0][1], a3 = board[0][2];
        char a4 = board[1][0], a5 = board[1][1], a6 = board[1][2];
        char a7 = board[2][0], a8 = board[2][1], a9 = board[2][2];
        
        if(countX-1 == countO) {
            if((a1==a2 && a2==a3 && a1=='O') || (a4==a5 && a5==a6 && a4=='O') || 
               (a7==a8 && a8==a9 && a7=='O') || (a1==a5 && a5==a9 && a1=='O') || 
               (a3==a5 && a5==a7 && a3=='O') || (a1==a4 && a4==a7 && a1=='O') ||
               (a2==a5 && a5==a8 && a2=='O') || (a3==a6 && a6==a9 && a3=='O'))
                return false;
            
             else return true;
        }
        
        else if(countX == countO){            
            if((a1==a2 && a2==a3 && a1=='X') || (a4==a5 && a5==a6 && a4=='X') ||
               (a7==a8 && a8==a9 && a7=='X') || (a1==a5 && a5==a9 && a1=='X') ||
               (a3==a5 && a5==a7 && a3=='X') || (a1==a4 && a4==a7 && a1=='X') ||
               (a2==a5 && a5==a8 && a2=='X') || (a3==a6 && a6==a9 && a3=='X'))
                return false;
            
            else return true;
        }   
        
        return false;
    }
};