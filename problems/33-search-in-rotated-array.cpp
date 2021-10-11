class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high =nums.size()-1, mid;

        //binary search
        while(high>=low){
            mid = low + ((high-low)>>1);
            
            if(nums[mid] == target) return mid;
            
            if(nums[low]<= nums[mid]){
                if(target<=nums[mid] && target>=nums[low]){
                    high = mid-1;
                }
                
                else low = mid+1; 
            }
            
            else{
                if(target>=nums[mid] && target<= nums[high]){
                    low = mid+1;
                }
                
                else high = mid-1;
            }
        }
        
        //if element is not found returning -1
        return -1;
    }
};