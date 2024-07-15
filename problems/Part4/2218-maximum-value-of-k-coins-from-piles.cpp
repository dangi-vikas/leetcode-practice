class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        int ans = maxValueOfCoins(piles, k, n-1, dp);

        return ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k, int pileIdx, vector<vector<int>>& dp) {
        if(pileIdx < 0 || k == 0) return 0;
        if(dp[pileIdx][k] != -1) return dp[pileIdx][k];

        int maxValue = maxValueOfCoins(piles, k, pileIdx-1, dp);
        int currValue = 0;

        for(int i=0; i<min(k, (int)piles[pileIdx].size()); i++) {
            currValue += piles[pileIdx][i];
            int valueOnPick = currValue + maxValueOfCoins(piles, k-i-1, pileIdx-1, dp);
            maxValue = max(maxValue, valueOnPick);
        }

        return dp[pileIdx][k] = maxValue;
    }
};