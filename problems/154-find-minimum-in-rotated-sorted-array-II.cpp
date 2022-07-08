class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(high >= low) {
            int mid = low + ((high-low) >> 1);
            
            if(nums[high] == nums[mid]) high--;
            else if(nums[high] > nums[mid]) high = mid;
            else low = mid + 1;
        }
        
        return nums[low];
    }
};