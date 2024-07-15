class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int currMax = nums[0], currMin = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            int temp = currMax;

            //finding the maximum at the current element
            currMax = max({nums[i], currMax*nums[i], currMin*nums[i]});

            /*finding the minimum in case if it is multiplied with a
              negative it will become positive*/
            currMin = min({nums[i], temp*nums[i], currMin*nums[i]});
            
            maxProduct = max(maxProduct, currMax);
        }
         
        return maxProduct;
    }
};