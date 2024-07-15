class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long maxVal = 0, prefixSum = 0;

        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];
            maxVal = max(maxVal, ((prefixSum + i) / (i+1)));
        }

        return maxVal;
    }
};