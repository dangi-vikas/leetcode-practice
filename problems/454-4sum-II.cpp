class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums;
        int count = 0;
        
        for(int num1 : nums1)
            for(int num2 : nums2){
                int sum = num1 + num2;
                sums[-sum]++;
            }
        
        for(int num3 : nums3)
            for(int num4 : nums4){
                int sum = num3 + num4;
                
                if(sums.find(sum) != sums.end())
                    count += sums[sum];
            }
        
        return count;
    }
};