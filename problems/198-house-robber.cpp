class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        //base cases
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        int val1 = nums[0], val2 = max(val1, nums[1]);
        for(int i=2; i<n; i++){
            int temp = val2;

            //choosing either val 2 or val1
            val2 = max(val2, val1+nums[i]);
            
            val1 = temp;
        }
        
        return val2;
    }
};