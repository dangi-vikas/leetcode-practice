class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), steps = 0;
        
        int median = !(n%2) ? (nums[n/2]+nums[n/2-1]) / 2 : nums[n/2];
        
        for(int num : nums)
            steps += abs(num - median);
        
        return steps;
    }
};