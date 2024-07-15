class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int productLeft = 1, productRight = 1;
       
        for(int i=1; i<n; i++) {
            productLeft *= nums[i-1];
            productRight *= nums[n-i];
 
            ans[i] *= productLeft;
            ans[n-i-1] *= productRight;
        }
        
        return ans;
    }
};
