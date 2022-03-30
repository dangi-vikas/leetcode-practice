class Solution {
    double dp[26][26][101];
    
public:
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, 0.0, sizeof(dp));
        return knightProbabilityRec(n, k,  row, column);
    }
    
    double knightProbabilityRec(int n, int k, int i, int j){
        if(i >= n || j >= n || i < 0 || j < 0 || k < 0) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] != 0) return dp[i][j][k];
        
        double total = knightProbabilityRec(n, k - 1, i - 2, j + 1) +

                       knightProbabilityRec(n, k - 1, i - 2, j - 1)  +

                       knightProbabilityRec(n, k - 1, i - 1, j + 2)  +

                       knightProbabilityRec(n, k - 1, i - 1, j - 2)  +

                       knightProbabilityRec(n, k - 1, i + 2, j + 1)  +

                       knightProbabilityRec(n, k - 1, i + 1, j + 2)  +

                       knightProbabilityRec(n, k - 1, i + 2, j - 1)  +

                       knightProbabilityRec(n, k - 1, i + 1, j - 2);

        return dp[i][j][k] = total / 8.0;
                
    }
};