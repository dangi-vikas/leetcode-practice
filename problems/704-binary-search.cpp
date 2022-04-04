class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        
        while (high >= low) {
            int mid = low + ((high - low) >> 1);
            
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};