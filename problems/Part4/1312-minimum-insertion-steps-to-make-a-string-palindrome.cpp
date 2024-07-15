class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int len=1; len<=n; len++) {
            for(int start=0; start<=(n-len); start++) {
                int end = start + len - 1; 

                if (len == 1) { 
                    dp[start][end] = 1;
                    continue; 
                }
                
                if (s[start] == s[end])
                    dp[start][end] = 2 + dp[start+1][end-1];

                else dp[start][end] = max(dp[start+1][end], dp[start][end-1]); 
            }
        }

        return n - dp[0][n-1];
    }
};