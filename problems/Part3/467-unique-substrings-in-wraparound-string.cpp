    class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size(), count, ans = 0;
        vector<int> dp(26, 0);
        
        for(int i=0; i<n; i++){
            if(i==0){
                count = 1;
                dp[p[i] - 'a'] = 1;
            }
            
            else{
                if((p[i] - p[i-1] - 1) % 26 == 0) count++;
                else count = 1;
                
                dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
            }
        }
        
        for(int i=0; i<26; i++)
            ans += dp[i];
        
        return ans;
    }
};