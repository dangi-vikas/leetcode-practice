class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i, j; i = j = INT_MAX;
        
        for(int x=0; x<nums.size(); x++){
            if(nums[x] <= i) i = nums[x];
            else if(nums[x] <= j) j = nums[x];
            else return true;
        }
        
        return false;
    }
};