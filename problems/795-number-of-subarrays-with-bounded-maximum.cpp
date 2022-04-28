class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, len = 0;
        int start = 0, end = 0;
        
        while(end < nums.size()) {
            if(nums[end] >= left && nums[end] <= right)
                len = end - start + 1;
            
            else if(nums[end] > right) {
                len = 0;
                start = end + 1;
            }
            
            ans += len;
            end++;
        }
        
        return ans;
    }
};