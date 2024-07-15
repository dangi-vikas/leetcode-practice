class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<int> next(n, 0);

        for(int c=0; c<n; c++) next[c] = matrix[n-1][c];

        for(int i=n-2; i>=0; i--) {
            vector<int> curr(n, 0);

            for(int j=0; j<n; j++) {
                int leftDiag = INT_MAX, down = INT_MAX, rightDiag = INT_MAX;

                if(j > 0) leftDiag = next[j-1];
                down = next[j];
                if(j < n-1) rightDiag = next[j+1];

                curr[j] = matrix[i][j] + min(leftDiag, min(down, rightDiag));
            }

            next = curr;
        }

        for(int c=0; c<n; c++) 
            ans = min(ans, next[c]);
       
        return ans;
    }

    int minFallingPathSumCol(vector<vector<int>>& matrix, int m, int n, int row, int col, vector<vector<int>>& dp) {
        int leftDiag = INT_MAX, down = INT_MAX, rightDiag = INT_MAX;

        if(row == n) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        if(col > 0) leftDiag = minFallingPathSumCol(matrix, m, n, row+1, col-1, dp);
        down = minFallingPathSumCol(matrix, m, n, row+1, col, dp);
        if(col < m-1) rightDiag = minFallingPathSumCol(matrix, m, n, row+1, col+1, dp);

        return dp[row][col] = matrix[row][col] + min(leftDiag, min(down, rightDiag));
    }
};
