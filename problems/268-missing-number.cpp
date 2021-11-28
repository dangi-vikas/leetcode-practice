class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR = nums[0];
        int XORn = 1;
        
        for(int i=1; i<nums.size(); i++)
            XOR ^= nums[i];
        
        for(int i=2; i<=nums.size(); i++)
            XORn ^= i;
        
        return XOR ^ XORn;
    }
};  