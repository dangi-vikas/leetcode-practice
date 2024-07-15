class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = low;
        
        while(high >= low) {
            int mid = low + ((high - low) >> 1);
            int partition = numPartitionInSumRange(mid, nums);
            
            if(partition > m) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    int numPartitionInSumRange(int maxSum, vector<int>& nums) {
        int subSum = 0, partition = 1;
        
        for(int num : nums) {
            if(subSum + num > maxSum) {
                partition++;
                subSum = num;
            }
            
            else subSum += num; 
        }
        
        return partition;
    }
};