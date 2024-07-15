class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int currMax = INT_MIN;
        int partition = 0;
        int leftMax = nums[0];
        
        for(int i=0; i<nums.size(); i++) {
            currMax = max(currMax, nums[i]);
            
            if(nums[i] < leftMax) {
                leftMax = currMax;
                partition = i;
            }
        }
        
        return partition + 1;
    }
};