class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mn = 0, ans = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < mn) {
                ans += mn - nums[i];
                nums[i] += mn - nums[i];
            }
            
            mn = nums[i] + 1;
        }
        
        return ans;
    }
};