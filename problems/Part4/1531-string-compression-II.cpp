class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n+1][k+2];
        
        for(int i=0; i<n+1; i++) 
            for(int j=0; j<k+2; j++) 
                dp[i][j] = 1e9;    
        
        dp[0][0] = 0; 
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=k; j++) {
                dp[i][j+1] = min(dp[i][j+1], dp[i-1][j]);

                int cnt = 0, del = 0;
                for(int l=i; l<=n; l++) {
                    if(s[i-1] == s[l-1]) cnt++;
                    else del++;
                    
                    if(j + del <= k) {
                        int len = dp[i-1][j] + 1;

                        if(cnt >= 100) len += 3;
                        else if(cnt >= 10) len += 2;
                        else if(cnt >= 2) len++;
                        else len += 0;

                        dp[l][j+del] = min(dp[l][j+del], len);
                    }

                    else break;
                }
            }
        }
        
        return dp[n][k];
    }
