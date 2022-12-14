class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];

        int next = nums[n-1], nextNext = max(next, nums[n-2]);

        for(int i=n-3; i>=0; i--) {
            int curr = max((nums[i] + next), nextNext);
            next = nextNext;
            nextNext = curr;
        }

        return nextNext;
    }

    int rob(vector<int>& nums, int index, vector<int>& dp) {
        if(index > nums.size()-1) return 0;

        if(dp[index] != -1) return dp[index];

        int choose = nums[index] + rob(nums, index+2, dp);
        int notChoose = rob(nums, index+1, dp);

        return dp[index] = max(choose, notChoose);
    }
};