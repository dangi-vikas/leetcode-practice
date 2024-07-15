class Solution {
    typedef long long ll;
    
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        ll prefixSum = 0, minDiff = INT_MAX;
        int ans = 0;
        
        for(int num : nums) sum += num;
        
        for(ll i=0; i<n; i++) {
            prefixSum += nums[i];
            
            ll prefixAverage = (ll) prefixSum / (i+1);
            ll suffixAverage = (i != n-1) ? (ll) (sum - prefixSum) / (n-i-1) : 0;
            ll currDiff = abs(prefixAverage - suffixAverage);
            
            if(minDiff > currDiff) {
                minDiff = currDiff;
                ans = i;
            } 
        }
        
        return ans;
    }
};