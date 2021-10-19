class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0, high =nums.size()-1;

        //binary search
        while(high>=low){

            int mid = low + ((high-low)>>1);

            if(nums[mid] == target) return true;
            
            //if duplicates are found at low and high
            if((nums[low]==nums[mid]) && (nums[high]==nums[mid])){
                low++; high--;
            }
            
            else if(nums[low]<= nums[mid]){
                if(target<nums[mid] && target>=nums[low]) high = mid-1;
                else low = mid+1; 
            }
            else{
                if(target>nums[mid] && target<= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        
        //if element is not found returning false
        return false;
    }
};
    