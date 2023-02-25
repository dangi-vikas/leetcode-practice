class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> v;
        
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(nums[i] + nums[j] == target){                //when the two numbers' sum is equal to target
                    v.push_back(i);
                    v.push_back(j);                             //pushing them in the vector
                }
            }
        } 
        
        return v;
    }
};
