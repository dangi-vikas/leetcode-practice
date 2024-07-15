class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(2*n + 1, -1));
        int sum = accumulate(piles.begin(), piles.end(), 0);

        return (sum + stoneGame(piles, n, 0, 1, dp)) >> 1;
    }

    int stoneGame(vector<int>& piles, int n, int ind, int m, vector<vector<int>>& dp) {
        if(ind >= n) return 0;
        if(dp[ind][m] != -1) return dp[ind][m];

        long long maxStones = INT_MIN;
        long long sum = 0;

        for(int x=0; x<2*m; x++) {
            if(ind + x < n) sum += piles[ind+x];
            maxStones = max(maxStones, (sum - stoneGame(piles, n, ind+x+1, max(m, x+1), dp)));
        }

        return dp[ind][m] = maxStones;
    }
};