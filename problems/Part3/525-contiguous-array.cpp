class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = 0, prefixSum = 0;
        counts[0] = -1;
        
        for(int i=0; i<nums.size(); i++){
            prefixSum += (nums[i] == 0) ? -1 : 1;
            
            if (counts.find(prefixSum) == counts.end()) 
                counts[prefixSum] = i;
                
            else ans = max(ans, i - counts[prefixSum]);
        }
        
        return ans;
    }
};
