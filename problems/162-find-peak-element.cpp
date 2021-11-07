class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(), low=0, high=n-1;
        
        //binary search
        while(low<high){
            int mid = low + ((high-low)>>1);
            
            /*if the next element increasing then we are bound
              to find peak in later half*/
            if(nums[mid] < nums[mid+1])
                low = mid+1;
            
            else high = mid;
        }
        
        return high;
    } 
};