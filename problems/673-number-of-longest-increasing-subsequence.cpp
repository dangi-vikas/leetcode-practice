class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1), count(n, 1);
        int ans=0, maxLen=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    if(length[i] == length[j] + 1)
                        count[i] += count[j];
                    else if(length[i] < length[j] + 1) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                }
                   
            }
            
            if(maxLen == length[i])
                ans += count[i];
            
            else if(maxLen < length[i]) {
                maxLen = length[i];
                ans = count[i];
            }
        }
        
        return ans;
    }
};