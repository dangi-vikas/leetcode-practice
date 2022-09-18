class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(m, 0);
        
        int minSum = 1e8;
        
        for(int i=0; i<m; i++) prev[i] = matrix[0][i];
        
        for(int i=1; i<n; i++) {
            vector<int> curr(m, 0);
            
            for(int j=0; j<m; j++) {
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j] + (j-1>=0 ? prev[j-1] : 1e8);
                int rd = matrix[i][j] + (j+1<m ? prev[j+1] : 1e8);
                
                curr[j] = min(u, min(ld, rd));
            }
            
            prev = curr;
        }
        
        for(int i=0; i<m; i++) 
            minSum = min(minSum, prev[i]);
        
        return minSum;
    }
};