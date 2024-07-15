class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;

        int n = nums.size();
        vector<int> ans(n, -1);

        if(k > n/2) return ans;

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) 
            prefix[i] = prefix[i-1] + nums[i];

        int divisor = 2*k+1;
        long sum = 0;

        for(int i=k; i<n-k; i++){
            ans[i] = (prefix[i+k] - sum) / divisor;
            sum += nums[i-k];
        }

        return ans;
    }
};