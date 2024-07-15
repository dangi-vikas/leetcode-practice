class Solution {
    const long long mod = 1e9 + 7;
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m+1, vector<int> (n+1, -1)));
        return findPathsRec(m, n, maxMove, startRow, startColumn, dp) % mod ;
    }
    
     int findPathsRec(const int& m, const int& n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp) {
        if(startRow >= m || startRow < 0 || startColumn >= n || startColumn < 0)
            return 1;
        
        if(maxMove == 0) return 0;
    
        if(dp[maxMove][startRow][startColumn] == -1) {
            int up = (findPathsRec(m, n, maxMove-1, startRow-1, startColumn, dp)) % mod;
            int down = (findPathsRec(m, n, maxMove-1, startRow+1, startColumn, dp)) % mod;
            int left = (findPathsRec(m, n, maxMove-1, startRow, startColumn-1, dp)) % mod;
            int right = (findPathsRec(m, n, maxMove-1, startRow, startColumn+1, dp)) % mod; 
        
            dp[maxMove][startRow][startColumn] = ((((up + down) % mod + left) % mod) + right) % mod;
        }
         
        return dp[maxMove][startRow][startColumn];
    }
};
