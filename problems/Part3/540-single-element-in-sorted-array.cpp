class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xOr =  nums[0];
        
        for(int i=1; i<nums.size(); i++) xOr ^= nums[i];
        
        return xOr;
    }
};