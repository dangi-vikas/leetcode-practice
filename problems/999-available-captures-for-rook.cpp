class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        int p = -1, q = -1;
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'R') {
                    p = i;
                    q = j;
                    break;
                }
            }
            
            if(p >= 0) break;
        }
        
        for(int i=p+1; i<board.size(); i++) {
            if(board[i][q] != '.') {
                if(board[i][q] == 'p') ans++;
                break;
            }
        }
        
        for(int i=p-1; i>=0; i--) {
            if(board[i][q] != '.') {
                if(board[i][q] == 'p') ans++;
                break;
            }
        }
        
        for(int j=q+1; j<board[0].size(); j++) {
            if(board[p][j] != '.') {
                if(board[p][j] == 'p') ans++;
                break;
            }
        }
        
        for(int j=q-1; j>=0; j--) {
            if(board[p][j] != '.') {
                if(board[p][j] == 'p') ans++;
                break;
            }
        }
        
        return ans;
    }
};