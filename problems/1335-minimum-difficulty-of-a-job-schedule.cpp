class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        
        int ans = minDifficultyRec(jobDifficulty, d, 0, n, dp);
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    int minDifficultyRec(vector<int>& difficulty, int d, int index, int n, vector<vector<int>>& dp) {
        if(d == 0) {
            if(index >= n) return 0;
            else return INT_MAX;
        }
        
        if(index == n) return INT_MAX;
        
        if(dp[index][d] != -1) return dp[index][d];
        
        int currMax = 0;
        long minDiff = INT_MAX;
        
        for(int i=index; i<n; i++) {
            currMax =  max(currMax, difficulty[i]);
            minDiff = min(minDiff, (long)currMax + minDifficultyRec(difficulty, d-1, i+1, n, dp));
        }
        
        return dp[index][d] = minDiff;
    }
};