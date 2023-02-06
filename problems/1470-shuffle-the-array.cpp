class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j = n;

        for(int i=1; i<=2*n; i+=2, j+=2) 
            nums.insert(nums.begin() + i, nums[j]);
        
        nums.resize(2*n);

        return nums;
    }
};