class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //finding the first occurance of the target by binary search
        int first = search(nums, target);
        
        //if the element is not found in the array
        if(first == nums.size() || nums[first] != target) return {-1, -1};
        
        /*last occurance is found out by finding the element 
          just greater than target and returning its prior index*/

        //returning the the first and last occurance  
        return {first, search(nums, target+1, first) - 1};
    }
    
    //binary search
    int search(vector<int>& nums, int target, int low = 0) {
        int high = nums.size()-1, mid;
        
        while(high >= low) {
            mid = low + ((high - low) >> 1);
            
            if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }

        return low;    
    }
};