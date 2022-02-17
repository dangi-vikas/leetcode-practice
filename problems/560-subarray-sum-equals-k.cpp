class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSum;
        int count = 0, currSum = 0;
        
        for(int i=0; i<n; i++) {
            currSum += nums[i];
            
            if(currSum == k) count++;
            
            if(prefixSum.find(currSum - k) != prefixSum.end())
                count += prefixSum[currSum - k];
            
            prefixSum[currSum]++;
        }
        
        return count;
    }
};