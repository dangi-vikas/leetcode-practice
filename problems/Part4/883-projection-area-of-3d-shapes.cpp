class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
       int ans = 0, n = grid.size();
  
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans += (grid[i][j] > 0);

        for(int i=0; i<n; i++) 
            ans += *max_element(grid[i].begin(), grid[i].end());

        for(int j=0; j<n; j++){
            int max_val{0};

            for(int i=0; i<n; i++)
                max_val = max(max_val, grid[i][j]);
           
            ans += max_val;
        }
        
        return ans;
    }
};
