class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> ans(numRows, vector<int>(numCols, 0));

        int i = 0, j = 0;

        while(i < numRows && j < numCols) {
            int val = min(rowSum[i], colSum[j]);
            ans[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            }
            
            if (colSum[j] == 0) {
                j++;
            }
        }
        
        return ans;
    }
};
