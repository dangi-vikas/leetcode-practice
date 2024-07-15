class Solution {
    vector<int> nums;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        vector<int> temp;
        
        for(int i =0; i<nums.size(); i++)
            if(nums[i] == target) temp.push_back(i);
        
        int index = rand() % temp.size();
            
        return temp[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */