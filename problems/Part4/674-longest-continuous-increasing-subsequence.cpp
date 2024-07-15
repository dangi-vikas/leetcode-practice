class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int LCIS = 0, curr = 1;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                LCIS = max(LCIS, curr);
                curr = 0;
            }
            
            curr++;
        }
        
        return max(LCIS, curr);
    }
};