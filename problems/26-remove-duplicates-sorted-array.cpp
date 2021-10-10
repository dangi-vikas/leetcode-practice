class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //if the nums array is empty
        if(nums.size()==0) return 0;
        
        int i=0;
        
        for(int j=1; j<nums.size(); j++){

            //if j is a different number swapping overriding it to the previous number
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        
        //length of the new array of distinct element 
        return i+1;
    }
};