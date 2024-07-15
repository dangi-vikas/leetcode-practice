class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int maxSum = kadaneAlgorithm(nums);
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            nums[i] = -nums[i];
        }
         
        int minSum = kadaneAlgorithm(nums);
        
        if(sum + minSum == 0) return maxSum;
        
        return max(maxSum, sum+minSum);
    }
    
    int kadaneAlgorithm(vector<int>& nums) {
        int finalMax = nums[0], currMax = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            currMax = max(currMax+nums[i], nums[i]);
            finalMax = max(currMax, finalMax);
        }
        
        return finalMax;
    }
};