class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //if the nums array is empty
        if(nums.size()==0) return 0;
        
        int i = 1, j = 1;
        
        while(j < nums.size()){

            //if j is a different number swapping overriding it to the previous number
            if(nums[j] != nums[j - 1]){
                nums[i] = nums[j];
                i++;
            }

            j++;
        }
        
        //length of the new array of distinct element 
        return i;
    }
};