class Solution {
    map<int,int> dp;

public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = (1 << n) - 1;
        return maxScore(n / 2, mask, nums);
    }

    int maxScore(int t, int mask, vector<int> &nums) {
        if(t == 0) return 0;
        if(dp[mask]) return dp[mask];

        int ans = 0;

        for(int i=0; i<nums.size(); i++) 
            for(int j=0; j<nums.size(); j++) 
                if((mask & (1 << i)) && (mask & (1 << j)) && (i != j)) 
                    ans=max(ans, t * __gcd(nums[i], nums[j]) + maxScore(t-1, mask ^ (1 << i) ^ (1 << j), nums));
             
        return dp[mask] = ans;
    }
};