class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        int negCount = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0) {
                nums[i] = 0;
                negCount++;
            }
        }
        
        for(const auto num : nums) {
            const int i = abs(num) - 1;
            
            if(i >= 0 && i < n) {
                int iVal = abs(nums[i]);
                nums[i] = iVal ? 0 - iVal : 0 - (i + 1);
            }
        }
        
        const int maxMissingNum = n - negCount + 1;
        
        for(int missingPositiveMin=1; missingPositiveMin<maxMissingNum; missingPositiveMin++) {
            if(nums[missingPositiveMin-1] >= 0) return missingPositiveMin;
        }
        
        return maxMissingNum;
    }
};
