//Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        //traversing the nums array
        for(auto i : nums){

            //adding the current number to currSum
            currSum += i;

            //finding maximum sum after each iteration
            maxSum = max(maxSum, currSum);

            //if the currSum is negative updating it to 0
            if(currSum < 0) currSum = 0;   
        }
        
        return maxSum;
    }
};