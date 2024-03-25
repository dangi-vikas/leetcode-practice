class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int num : nums) {
            num = abs(num);
            
            if(nums[num-1] > 0) nums[num-1] *= -1;
            else ans.push_back(num);
        }
        
        return ans;
    }
};
