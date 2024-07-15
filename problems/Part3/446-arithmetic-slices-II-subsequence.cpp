class Solution {
    typedef long long ll;

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
	vector<unordered_map<long, long>> dp(n);
        
	for(int i=0; i<n; i++) {
	    for(int j=0; j<i; j++) {
		ll diff = (ll) nums[i] - (ll) nums[j];

		dp[i][diff]++;
                
		if(dp[j].find(diff) != dp[j].end()) {
		    dp[i][diff] += dp[j][diff];
		    ans += dp[j][diff];
		}
	    }
	}
        
	return ans;
    }
};
	
