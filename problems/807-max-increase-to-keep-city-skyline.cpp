class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n =  grid.size();
        int ans = 0;
        
        vector<int> maxRowVals(n, 0), maxColVals(n, 0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                maxRowVals[i] = max(maxRowVals[i], grid[i][j]);
                maxColVals[j] = max(maxColVals[j], grid[i][j]);
            }
        }
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++) 
                ans += min(maxRowVals[i], maxColVals[j]) - grid[i][j];
            
        return ans;
    }
};