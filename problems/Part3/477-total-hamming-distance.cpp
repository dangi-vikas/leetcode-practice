class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<32; i++){
            int one = 0, zero = 0;
            int k = (1<<i);
            
            for(int j = 0; j<n; j++){
                if(nums[j] & k) one++;
                if(!(nums[j] & k)) zero++;
            }
            
            if(one == n || zero == n) continue;
            else ans += (one * zero);
        }
        
        return ans;
    }
};