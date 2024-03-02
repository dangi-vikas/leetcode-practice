class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i=0, j=n-1, k=n-1; i<=j; k--) {
            if (abs(nums[j]) > abs(nums[i])) {
                ans[k] = nums[j] * nums[j];
                j--;
            }
             
            else {
                ans[k] = nums[i] * nums[i];
                i++;
            }
        }     
        
        return ans;
    }
};