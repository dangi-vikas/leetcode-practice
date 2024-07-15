class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total, overlap, nonZero;
        
        total = overlap = nonZero = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) continue;
                
                nonZero++;
                total += grid[i][j];
                
                if (i + 1 < m)
                    overlap += min(grid[i][j], grid[i+1][j]);
                
                if (j + 1 < n)
                    overlap += min(grid[i][j], grid[i][j+1]);
            }
        }
        
        int area = (total * 4) + (2 * nonZero) - (overlap * 2);
        
        return area;
    }
};