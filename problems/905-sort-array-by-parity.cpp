class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, e = nums.size() - 1;
        
        while(i < e) {
            if(nums[i] % 2 == 1 && nums[e] % 2 == 0) {
                swap(nums[i], nums[e]);
                i++;
                e--;
            }
            
            else if(nums[i] % 2 == 0 && nums[e] % 2 == 0)
                i++;
            
            else if(nums[i] % 2 == 1 && nums[e] % 2 == 1)
                e--;

            else {
                i++;
                e--;
            }
        }
    
        return nums;
    }
};
