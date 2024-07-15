class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        
        if(m == 0 || n == 0) return ans;
        
        vector<vector<int>> pacific(m, vector<int>(n, false));               vector<vector<int>> atlantic(m, vector<int>(n, false));
            
        for(int j=0; j<n; j++)  {
            dfs(heights, 0, j, INT_MIN, pacific);
            dfs(heights, m-1, j, INT_MIN, atlantic);
        }
    
        for(int i=0; i<m; i++)  {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, n-1, INT_MIN, atlantic);
        }
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            
        return ans;
    }
    
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& ocean){
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        
        if(i<0 || i>=ocean.size() || j<0 || j>=ocean[0].size())
            return;
        
        if(heights[i][j]<prev || ocean[i][j]) return;
        ocean[i][j] = true;
        
        for(auto d: dir)
            dfs(heights, i+d[0], j+d[1], heights[i][j], ocean);
    }
};