class Solution {
    typedef long long ll;
    int mod = 1e9 + 7;

public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1, vector<int>(goal+1, -1));
        return numMusicPlaylists(n, goal, k, dp);
    }

    ll numMusicPlaylists(int n, int goal, int& k, vector<vector<int>>& dp) {
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0) return 0;

        if(dp[n][goal] != -1) return dp[n][goal];

        ll pickNew = numMusicPlaylists(n-1, goal-1, k, dp) * n;
        ll notPickNew = numMusicPlaylists(n, goal-1, k, dp) * max(n-k, 0);

        return dp[n][goal] = (pickNew + notPickNew) % mod;
    }
};