class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        
        for (int y=0; y<n; y++) {
            for (int x=0; x<m; x++) {
                int count{0};
                
                for (int i=-1; i<=1; i++) {
                    for (int j=-1; j<=1; j++) {
                        const int dy{y + i}, dx {x + j};
                        
                        if (dy>=0 && dy<n && dx>=0 && dx<m) {
                            ans[y][x] += img[dy][dx];
                            count++;
                        }
                    }
                }
                
                ans[y][x] /= count;
            }
        }
         
        return ans;
    }
};
