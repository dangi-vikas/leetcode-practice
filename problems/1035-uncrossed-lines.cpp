class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        return maxUncrossedLines(nums1, nums2, 0, 0, dp);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp){
        if(i >= nums1.size() || j >= nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(nums1[i] == nums2[j]) 
            ans = 1 + maxUncrossedLines(nums1, nums2, i+1, j+1, dp);
        
        ans = max({ans, maxUncrossedLines(nums1, nums2, i+1, j, dp), maxUncrossedLines(nums1, nums2, i, j+1, dp)});

        return dp[i][j] = ans;
    }
};