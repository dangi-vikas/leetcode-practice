class Solution {
public:
    int numberOfArrays(string s, int k) {
        int mod = 1000000007;
        int n = s.size();
        vector<int>dp(n + 1, 0);
        
        dp[n] = 1; 

        for(int startIdx=n-1; startIdx>=0; startIdx--) {
            long long currNum = 0, ways = 0;
            
            for(int i=startIdx; i<s.size(); i++) {
                int currDig = s[i] - '0';
                currNum = (currNum * 10) + currDig; 

                if(currNum < 1 || currNum > k) break;
 
                ways = (ways +  dp[i+1]) % mod;
            }

            dp[startIdx] = ways;
        }

        return dp[0];
    }
};s