class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, j=0;
        int maxSum, sum = 0;
        
        while(j < k) {
            sum += nums[j];
            j++;
        }
        
        maxSum = sum;
        i++; 
        
        while(j < nums.size()) {
            sum += nums[j] - nums[i-1];
            maxSum = max(maxSum, sum);
            
            i++; j++;
        }
        
        return (double)maxSum / k;
    }
};