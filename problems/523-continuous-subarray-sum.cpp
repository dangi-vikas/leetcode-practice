class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remMap= {{0, -1}};
        int remainder = 0;
        
        for(int  i=0; i<nums.size(); i++) {
            remainder += nums[i];
            
            if(k) emainder %= k;
            
            if(remMap.find(remainder) != remMap.end()) {
                if(i - remMap[remainder] > 1) return true;
            }
            
            else remMap[remainder] = i;
        }
        
        return false;
    }
};
