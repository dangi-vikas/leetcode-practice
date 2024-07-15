class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        
        unordered_map<int, int> counts;
        int pairCount = 0;
        
        for(int num : nums) counts[num]++;
        
        if(k == 0) {
            for(auto count : counts) 
                if(count.second > 1) pairCount++;
            
            return pairCount; 
        }
        
        for(auto count : counts) {
            if(counts.find(count.first - k) != counts.end())
                pairCount++;
        }
        
        return pairCount;
    }
};