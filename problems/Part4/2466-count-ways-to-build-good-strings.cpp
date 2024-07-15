class Solution {
    int mod = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1, -1);
        return countGoodStrings(low, high, zero, one, 0, dp);
    }

    int countGoodStrings(int& low, int& high, int& zero, int& one, long long length, vector<long long>& dp) {
        if(length > high) return 0;
        if(dp[length] != -1) return dp[length];

        long long ans = 0;

        if(length >= low && length <= high) ans = 1;

        ans += (countGoodStrings(low, high, zero, one, length+zero, dp) % mod);
        ans = ((ans % mod) + countGoodStrings(low, high, zero, one, length+one, dp) % mod) % mod;

        return dp[length] = ans;
    }
};s