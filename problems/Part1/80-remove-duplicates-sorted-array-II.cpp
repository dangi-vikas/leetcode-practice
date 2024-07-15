class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //if the array size is less than or 2 
        if(nums.size() <= 2) return nums.size();
        
        int i = 2;
        for(int j=2; j<nums.size(); j++){

            //if j is a different number swapping overriding it to the second previous number
            if(nums[j] != nums[i-2]){
                nums[i++] = nums[j];
            }
        }

        //length of the new array of distinct elements
        return i;
    }
};