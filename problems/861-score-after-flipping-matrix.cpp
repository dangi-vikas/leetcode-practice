class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++)
            if(grid[i][0] == 0)
                for(auto &j : grid[i]) j = !j;

            int m = grid.size();
            int n = grid[0].size();

            int tt = 1 << (n - 1);
            int ans = m * tt;
        
            tt >>= 1;

            for(int i=1; i<n; i++){
                int t = 0;
                for(int j=0; j<m; j++)
                    if(grid[j][i] == 1) t++;

                if(2*t < m) t = m - t;

                ans += t * tt;
                tt >>= 1;
        }

        return ans;
    }
};