class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> bucket(1001);
        int total = nums.size();
        
        for(int num : nums) 
            bucket[num]++;
        
        for(int i=0; i<1001; i++) {
            if(i == total) return i;
            total -= bucket[i];
        }
        
        return -1;
    }
};
