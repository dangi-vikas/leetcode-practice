class Solution {
    int count = 0;
    
public:
    int totalNQueens(int n) {
        vector<int> leftrow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        totalNQueensRec(0, leftrow, upperDiagonal, lowerDiagonal, n);
        return count;
    }
    
    void totalNQueensRec(int col, vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        if(col == n) {
            count++;
            return;
        }
        
        for(int row=0; row<n; row++) {
            if(leftrow[row] == 0 && upperDiagonal[n-1 + col - row] == 0 && lowerDiagonal[col+row] == 0) {
                leftrow[row] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                lowerDiagonal[col+row] = 1;
                
                totalNQueensRec(col+1, leftrow, upperDiagonal, lowerDiagonal, n);
                
                leftrow[row] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                lowerDiagonal[col+row] = 0;
            }
        }
    }
    
};