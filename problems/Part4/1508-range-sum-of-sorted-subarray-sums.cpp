class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        int ans = 0;
        int mod = 1000000007;
        
        for(int i=0; i<n; i++) {
            int prefix = 0;
            
            for(int j=i; j<n; j++) {
                prefix += nums[j];
                arr.push_back(prefix);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i=left-1; i<right; i++) {
            ans = (ans + arr[i]) % mod;
        }
        
        return ans;
    }
};