class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        //catalan number formula
        for(int i=2; i<=n; i++){
            int l=0, r=i-1;
            
            while(l<=i-1){
                dp[i] += dp[l]*dp[r];

                l++; r--;
            }
        }
        
        return dp[n];
    }
};
