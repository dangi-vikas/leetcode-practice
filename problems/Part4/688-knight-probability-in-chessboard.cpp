class Solution {
    double dp[26][26][101];
    vector<int> dx = {2, -2, 2, -2, 1, -1, 1, -1};
    vector<int> dy = {-1, -1, 1, 1, -2, -2, 2, 2}; 

public:
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, 0.0, sizeof(dp));
        return knightProbablityRec(n, k, row, column);
    }

    double knightProbablityRec(int n, int k, int r, int c) {
        if(r < 0 || c < 0 || r >= n || c >= n || k < 0) return 0;
        if(k == 0) return 1;
        if(dp[r][c][k] != 0) return dp[r][c][k];

        double totalOutcomes = 0.0;

        for(int d=0; d<8; d++) {
            int x = r + dx[d];
            int y = c + dy[d];
            
            totalOutcomes += knightProbablityRec(n, k-1, x, y); 
        }
        
        return dp[r][c][k] = totalOutcomes / 8.0;
    }
};