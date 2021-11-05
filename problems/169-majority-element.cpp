class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_ele=nums[0];
        
        for(int i=1,effvotes=1; i<nums.size(); i++){
            if(effvotes==0){
                effvotes=1;
                majority_ele=nums[i];
            }
            else{
                if(majority_ele==nums[i]) effvotes++;
                else effvotes--;
            }
        } 
        
        return majority_ele;
    }
};