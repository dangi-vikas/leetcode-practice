class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        unsigned long long up = 1, down = 1;
        
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1])
                up = down + 1;
            else if(nums[i] > nums[i+1])
                down = up + 1;
        }
        
        return max(up, down);
    }
};