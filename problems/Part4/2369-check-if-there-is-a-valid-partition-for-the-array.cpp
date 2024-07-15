class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return validPartition(nums, 0, nums.size(), dp);
    }

    bool validPartition(vector<int>& nums, int ind, int n, vector<int>& dp) {
        if(ind >= n) return true;
        if(dp[ind] != -1) return dp[ind];

        if(ind+1 < n && nums[ind+1] == nums[ind]) 
            if(validPartition(nums, ind+2, n, dp)) return dp[ind] = true;

        if(ind+2 < n && nums[ind+2] == nums[ind+1] && nums[ind+1] == nums[ind]) 
            if(validPartition(nums, ind+3, n, dp)) return dp[ind] = true;

        if(ind+2 < n && (nums[ind+2] == nums[ind+1] + 1) && (nums[ind+1] == nums[ind] + 1))
            if(validPartition(nums, ind+3, n, dp)) return dp[ind] = true;

        return dp[ind] = false;
    }
};