class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dupl, numSum = 0;
        
        for(int num : nums) {
            numSum += abs(num);
            
            if(nums[abs(num) - 1] < 0)
                dupl = abs(num);
            else nums[abs(num) - 1] *= -1;
        }
        
        int nSum = n * (n+1) / 2;
        
        return {dupl, dupl + (nSum - numSum)};
    }
};