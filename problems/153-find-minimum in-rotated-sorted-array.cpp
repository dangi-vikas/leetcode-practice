class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinRec(nums, 0, nums.size()-1);
    }
    
    //using binary search to find minimum
    int findMinRec(vector<int>& nums, int low, int high){
        if(low == high) return nums[low];
        
        int mid = low + ((high-low)>>2);
        
        if(nums[mid]<nums[high]) return findMinRec(nums, low, mid);
        if(nums[mid]>nums[high]) return findMinRec(nums, mid+1, high);
        
        return nums[high];
    }
};