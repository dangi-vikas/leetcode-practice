class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(21, vector<int> (21, -1));
        return predictTheWinner(0, nums.size() - 1, nums, dp) >= 0;
    }

    int predictTheWinner(int start, int end, vector<int>& nums, vector<vector<int>>& dp) {
        if (start == end) return nums[start];
        if(dp[start][end] != -1) return dp[start][end];

        int pickStart = nums[start] - predictTheWinner(start + 1, end, nums, dp);
        int pickEnd = nums[end] - predictTheWinner(start, end - 1, nums, dp);

        return dp[start][end] = max(pickStart, pickEnd);
    }

};