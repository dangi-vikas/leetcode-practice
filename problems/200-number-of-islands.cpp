class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int noIslands = 0;
        
        //traversing through the matrix
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)

                //if land is found
                if(grid[i][j] == '1') {

                    //initiating dfs
                    dfs(grid, i, j, m, n);

                    //increasing the count of islands
                    noIslands++;
                }
        
        return noIslands;
    }
    
     void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){

        //if the element is out of bound or is water/already visited  
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] != '1') return ;
        
        //marking as visited
        grid[i][j] = '2';
        
        //initiating dfs in all directions
        dfs(grid, i+1, j, m, n); 
        dfs(grid, i, j+1, m, n); 
        dfs(grid, i-1, j, m, n); 
        dfs(grid, i, j-1, m, n); 
     }
};