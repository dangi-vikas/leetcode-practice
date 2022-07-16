class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxGap = 0;
        int n = nums.size();
        
        if(n < 2) return 0;
        
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        
        int bucketSize = (int) ceil((double)(mx-mn) / (n-1));
        
        vector<int> maxOfBucket(n-1, INT_MIN), minOfBucket(n-1, INT_MAX);
        
        for(int i=0; i<n; i++) {
            if(nums[i] == mn || nums[i] == mx) continue;
            
            int bucketIndex = (nums[i] - mn) / bucketSize;
            
            minOfBucket[bucketIndex] = min(minOfBucket[bucketIndex], nums[i]);
            maxOfBucket[bucketIndex] = max(maxOfBucket[bucketIndex], nums[i]);
        }
        
        for(int i=0; i<n-1; i++) {
            if(maxOfBucket[i] == INT_MIN) continue;
            
            maxGap = max(maxGap, minOfBucket[i] - mn);
            mn = maxOfBucket[i];
        }
        
        maxGap = max(maxGap, mx-mn);
        
        return maxGap;
    }
};