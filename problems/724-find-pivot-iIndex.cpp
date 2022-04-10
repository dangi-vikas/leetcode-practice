class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int postfixSum = 0, prefixSum = 0; 
        
        postfixSum = accumulate(nums.begin(), nums.end(), 0);
        
        for(int i=0; i<nums.size(); i++) {
            postfixSum -= nums[i];
            if(prefixSum == postfixSum) return i;
            prefixSum += nums[i];
        }
        
        return -1;
    }
};