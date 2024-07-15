class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        //n^n=0 and n^0=m 
        for(int num : nums){
            ans ^= num;
        }
         
        return ans;
    }
};