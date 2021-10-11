class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i, j;
        
        //when only one or no permutation is possible
        if(nums.size()<=1) return;
        
        //getting the third priority number in current permutation
        for(i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) break;
        }
        
        if(i>=0){

            //finding the second priority number in current permutation
            for(j=n-1; j>=0; j--){
                if(nums[j]>nums[i]) break;
            } 

            //swaping the second and third for getting the next permutation
            swap(nums[j], nums[i]);
        }

        /*reversing the remaining number to get the least valued permutation
         as they will be then sorted in ascending order*/
         
        reverse(nums.begin()+i+1, nums.end());
       
    }
};