class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> inputGrid = buildGrid(n, mines);
        vector<vector<int>> dp(n, vector<int>(n, n));
        int sum;
        
        for(int i=0; i<n; i++) {    
            sum = 0;
            for(int j=0; j<n; j++) {
                if(inputGrid[i][j] == 0) sum = 0;
                else sum++;
                
                dp[i][j] = min(dp[i][j], sum);
            }
            
            sum = 0;
            for(int j=n-1; j>=0; j--) {
                if(inputGrid[i][j] == 0) sum = 0;
                else sum++;
                
                dp[i][j] = min(dp[i][j], sum);
            }
        }
        
        
        for(int i=0; i<n; i++) {
            sum = 0;
            for(int j=0; j<n; j++) {
                if(inputGrid[j][i] == 0) sum = 0;
                else sum++;
                
                dp[j][i] = min(dp[j][i], sum);
            }
            
            sum = 0;
            for(int j=n-1; j>=0; j--) {
                if(inputGrid[j][i] == 0) sum = 0;
                else sum++;
                
                dp[j][i] = min(dp[j][i], sum);
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> buildGrid(int n, vector<vector<int>>& mines) {
        vector<vector<int>> inputGrid(n, vector<int>(n, 1));
        
        for(auto mine : mines) 
            inputGrid[mine[0]][mine[1]] = 0;
        
        return inputGrid;
    }
};