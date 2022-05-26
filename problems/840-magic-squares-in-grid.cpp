class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        
        if(grid.size() == 1 || grid[0].size() == 1)
            return 0;
        
        for (int i=0; i<grid.size()-2; i++)
            for (int j=0; j<grid[0].size()-2; j++)
                 if(isMagicBox(grid, i, j)) 
                     ans++;
        
         return ans;
    }
    
    bool isMagicBox(vector<vector<int>>& grid, int x, int y) {
        if (grid[x+1][y+1] != 5)
            return false;
        
        bool flag = false;
        int rowSum = 0;
        
        for (int r=x; r<x+3; r++) {
            rowSum = 0;
            
            for (int c=y; c<y+3; c++) {
                rowSum += grid[r][c];
                flag = !flag;
                
                if (r == x+1 && c == y+1) continue;
                if (isEven(grid[r][c]) != flag) return false;
            }
            
            if (rowSum != 15) return false;
        }
        
        return grid[x][y] + grid[x+1][y] + grid[x+2][y] == 15;
    }
    
    bool isEven(int n) {
        return (n & 1) == 0;
    }
};