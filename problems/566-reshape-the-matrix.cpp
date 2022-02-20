class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        int o = m*n;
        
        if(r*c != o) return mat;
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for (int i=0; i<o; i++)
            ans[i/c][i%c] = mat[i/n][i%n];
        
        return ans;
    }
};