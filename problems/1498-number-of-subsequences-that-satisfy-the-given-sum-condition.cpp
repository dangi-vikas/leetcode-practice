class Solution {
    int mod = 1e9 + 7;
    
public:
    int numSubseq(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        long long count = 0;
        vector<int> pow(nums.size(), 1);
        
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++) 
            pow[i] = (pow[i-1] * 2) % mod;
        
        while(i <= j) {
            if((nums[i] + nums[j]) <= target) 
                count = (count + pow[j - i++]) % mod;
                
            else j--;
        }
        
        return count;
    }
};
