class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(!mat.size() || !mat[0].size()) return {};
        
        int m = mat.size(), n = mat[0].size();
        vector<int> ans(m * n);
        int i = 0;
        int row = 0, col = 0;
        bool up = true;
        
        while(row < m && col < n) {
            if(up) {
                while(row > 0 && col < n-1) {
                    ans[i++] = mat[row][col];
                    row--; col++;
                }
                ans[i++] = mat[row][col];
                
                if(col == n-1) row++;
                else col++;
            }
            
            else {
                while(row < m-1 && col > 0) {
                    ans[i++] = mat[row][col];
                    row++; col--;
                }
                ans[i++] = mat[row][col];
                
                if(row == m-1) col++;
                else row++;
            }
            
            up = !up;
        }
        
        return ans;
    }
};