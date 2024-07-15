class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,bool> visited;
        
        //iterating through board for visiting every cell ones
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                //checking only if the cell contains a number
                if(board[i][j] != '.'){
                    
                    //inserting the row column and box number and corresponding value
                    string Row = "R" + to_string(i) + to_string(board[i][j]);
                    string Column = "C" + to_string(j) + to_string(board[i][j]);
                    
                    int boxNumber = ((i/3)*3) + (j/3);
                    string Box = "B" + to_string(boxNumber) + to_string(board[i][j]);
                    
                    //the value is not insertable implies that it already exist in the hashmap
                    //this fails validity of sudoku 
                    if(!visited.insert({ Row, true}).second || 
                       !visited.insert({ Column, true}).second || 
                       !visited.insert({ Box,true}).second)    
                        return false;
                    
                }
            }            
        }
        
        return true;
    }
};