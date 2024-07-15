class Solution {
public:
    int findLHS(vector<int>& nums) {
        int longestSubs = 0;
        unordered_map<int, int> numMap;
        
        for(auto &num : nums) {
            numMap[num]++;
            
            if(numMap.count(num-1) > 0)
                longestSubs = max(longestSubs, numMap[num-1] + numMap[num]);
            
            if(numMap.count(num+1) > 0)
                longestSubs = max(longestSubs, numMap[num+1] + numMap[num]);
        }
         
        return longestSubs;
    }
};