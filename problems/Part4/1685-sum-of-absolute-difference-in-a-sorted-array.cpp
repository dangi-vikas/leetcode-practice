class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0, n = nums.size();
        int leftsum = 0;
        vector<int> ans(n);

        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
            
        for(int i=0; i<n; i++) {
            ans[i] = (nums[i] * i - leftsum) + 
                     ((sum - leftsum - nums[i]) - (nums[i] * (n-i-1)));

            leftsum += nums[i];
        }

        return ans;
    }
};