class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, i=0, j=0, len = INT_MAX;
        
        while(j<nums.size()){
            sum += nums[j++];
            
            //if the sum of elements is greater than target
            while(sum >= target && i<j){
                
                //finding the minimum length
                len = min(len, j-i);
                sum -= nums[i++];
            }
        }
        
        //if the subarray is found/ not found
        return len == INT_MAX ? 0 : len; 
    }
};