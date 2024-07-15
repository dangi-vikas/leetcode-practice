class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex, mx = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > mx) {
                mx = nums[i];
                maxIndex = i;
            }
        }
        
        for(int i=0; i<nums.size(); i++) 
            if(nums[i] != mx && mx < 2*nums[i])
                return -1;
        
        return maxIndex;
    }
};