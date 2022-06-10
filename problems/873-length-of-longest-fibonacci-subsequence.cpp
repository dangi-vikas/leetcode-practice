int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxi = 0;
        
        for(int i=2; i<n; i++) {
            int l = 0, r = i-1;
            
            while(l < r) {
                int sum = a[l] + a[r];
                if(sum > a[i]) r--;
                else if(sum < a[i]) l++;
                else {
                    dp[r][i] = dp[l][r] + 1;
                    maxi = max(maxi, dp[r][i]);
                    l++;
                    r--;
                }
            }
        }
        
        return maxi == 0 ? 0 : maxi+2;