class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i=0; i<n; i++)
            for(int j=1; j<m; j++)
                matrix[i][j] += matrix[i][j-1];
        
        int ans = INT_MIN;
        
        for(int l=0; l<m; l++) {
            for(int r=l; r<m; r++) {
                vector<int> rec = {0};
                int curr = 0;
                
                for(int i=0; i<n; i++) {
                    curr += matrix[i][r];
                    curr -= l > 0 ? matrix[i][l-1] : 0;
                    
                    for(auto it : rec) 
                        if(curr - it <= k && curr - it > ans)
                            ans = curr - it;
                
                    rec.push_back(curr);
                }
            }
        }
        
        return ans;
    }
};