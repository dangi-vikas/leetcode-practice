class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        //iterating through the matrix
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)

                //initiating BFS
                if(board[i][j] == word[0] && bfs(board, i, j, word, 0, visited))
                    return true;
            
        return false;
    }
                         
    bool bfs(vector<vector<char>>& board, int i, int j, string word, int index,
                vector<vector<bool>>& visited){
        
        //if all the characters in the word string are checked 
        if(index==word.size()-1) return true;
        
        //marking visited for current character
        visited[i][j] = true;
        
        //checking in all the direction for the next character
        if(i>0 && !visited[i-1][j] && board[i-1][j]==word[index+1] && bfs(board, i-1, j,
           word, index+1, visited)) return true;
        if(j>0 && !visited[i][j-1] && board[i][j-1]==word[index+1] && bfs(board, i, j-1,
           word, index+1, visited)) return true;
        if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j]==word[index+1] &&
           bfs(board, i+1, j, word, index+1, visited)) return true;
        if(j<board[0].size()-1 && !visited[i][j+1] && board[i][j+1]==word[index+1] &&
           bfs(board, i, j+1, word, index+1, visited)) return true;
        
        //backtracking step: marking the current charcter as unvisited if the word is not found
        visited[i][j] = false;
        
        //if the word is not found 
        return false;
    }
};