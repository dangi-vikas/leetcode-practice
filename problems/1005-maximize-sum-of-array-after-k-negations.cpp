class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i = 0, n = nums.size();
        
        while((i < n) && k) {
            if(nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
            
            else break;
            
            i++;
        }
        
        if(k % 2) {
            if(i == n) nums[i-1] = -nums[i-1];
            
            else if(i>0 && nums[i]>nums[i-1])
                nums[i-1] = -nums[i-1];
            
            else nums[i] = -nums[i];
        }
        
        int sum = 0;
        
        for(int& i : nums) sum += i;
        
        return sum;
    }
};