class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = maxi - mini - 2 * k;
        
        if(ans < 0) return 0;
        
        return ans;
    }
};