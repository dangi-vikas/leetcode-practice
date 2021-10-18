//Dutch National Flag Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, high=nums.size()-1; 
        int mid = 0;
        
        while(high>=mid){
            switch(nums[mid]){

                //if the element is 0
                case 0: swap(nums[low++], nums[mid++]);
                        break;

                //if the element is 1   
                case 1: mid++;
                        break;
                
                //if the element is 2
                case 2: swap(nums[high--], nums[mid]);
                        break;
            }
        }
    }
};