class Solution {
public:
    int maximumSwap(int num) {
        vector<int> rightMaxIndex(10, -1);
        string nums = to_string(num);
        
        for(int i=0; i<nums.length(); i++) 
            rightMaxIndex[nums[i] - '0'] = i;
        
        for(int i=0; i<nums.length(); i++) {
            int digit = nums[i] - '0';
            
            for(int j=9; j>digit; j--) {
                if(rightMaxIndex[j] !=- 1 && rightMaxIndex[j] > i) {
                    swap(nums[i], nums[rightMaxIndex[j]]);
                    return stoi(nums);
                }
            }
        }
        
        return stoi(nums);
    }
};