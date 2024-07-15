class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        //base cases
        if(n <= 3){
            return *max_element(nums.begin(), nums.end());
        }   
        
        return max(robRec(0, n -1, nums), robRec(1, n, nums));
    }
    
    int robRec(int index, int n, vector<int>& nums) {
        int val1 = 0, val2 = 0;

        for(int i = index; i < n; i++){
            int temp = val2;

            //choosing either val 2 or val1
            val2 = max(val2, val1+nums[i]);

            val1 = temp;
        }
        
        return val2;
    }
};