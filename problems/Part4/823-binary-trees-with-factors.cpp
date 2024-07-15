class Solution {
    long mod = 1000000007;
        
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long> dp;
        int ans = 0;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++){
            dp[arr[i]] = 1;
            
            for(int j=0; j<i; j++){
                if(arr[i] % arr[j] != 0) continue;
                int val = arr[i] / arr[j];
                
                if(dp.find(val) != dp.end())
                    dp[arr[i]] += (dp[arr[j]] * dp[val]) % mod;
            }
            
            ans = (ans + dp[arr[i]]) % mod;
        }
        
        return ans;
    }
};