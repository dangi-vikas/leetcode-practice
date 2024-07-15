class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(1001, 1));
        int ans = 1, diff;

        for(int ind=0; ind<n; ind++) {
            for(int prevInd=0; prevInd<ind; prevInd++) {
                diff = nums[ind] - nums[prevInd];
                dp[ind][diff+500] = max(dp[ind][diff+500], 1 + dp[prevInd][diff+500]);
                ans = max(ans, dp[ind][diff+500]);
            }
        }
        return ans;
    }
};