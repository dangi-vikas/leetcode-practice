class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        
        for(int i=0; i<grid[0].size(); i++) 
            dfs(grid, 0, i, ans);   
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, vector<int>& ans) {
        if(row == grid.size()) {
            ans.push_back(col);
            return;
        }
        
        if(grid[row][col] == 1){
            if(col >= grid[0].size()-1 || grid[row][col+1] != 1) {
                ans.push_back(-1);
                return;
            }
            
            else dfs(grid, row+1, col+1, ans);
        }
            
        else {
            if(col < 1 || grid[row][col-1] != -1) {
                ans.push_back(-1);
                return;
            }
            
            else dfs(grid, row+1, col-1, ans);
        }
    }
};