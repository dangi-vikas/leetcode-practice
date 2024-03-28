class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        
        while(r < n) {
            int curr = nums[r++];
            count[curr]++;
            
            while(l < r && count[curr] > k)
                count[nums[l++]]--;
            
            ans = max(ans, r-l);
        }
        
        return ans;
    }
};
