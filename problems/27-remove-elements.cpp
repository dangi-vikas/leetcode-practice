class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        //if the nums array is empty
        if(nums.size()==0) return 0;
        
        int i=0;
        
        for(int j=i; j<nums.size(); j++){

            //if the current element is equal to val then overriding it to the starting elements
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }

        //length of the new array 
        return i; 
    }
};