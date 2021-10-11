class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;

        //Binary Search      
        while(high>=low){
            int mid = low + ((high-low)>>2);
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        
        /*the insert position will be low because it 
          will be the index of immediate lower element than target*/
        return low;
    }
};