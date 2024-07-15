class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int n = nums.size();
        int count = 0, start = 0, end = 0;
        long long currProd = 1;
        
        while(end < n) {
            currProd *= nums[end];
            
            while(start <= end && currProd >= k) {
                currProd /= nums[start];
                start++;
            }
            
            count += (end - start + 1);
            end++;
        }
        
        return count;
    }
};
