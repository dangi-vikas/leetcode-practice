class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> counts(10001);
        
        for(int num : nums)
            if(++counts[num] == size(nums) / 2) return num;
        
        return 0; 
    }
};