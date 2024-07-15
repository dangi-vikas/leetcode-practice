class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].length();
        vector<vector<ll>> freq(n, vector<ll>(26, 0));  
        vector<vector<ll>> dp(n, vector<ll>(target.size(), -1));

        for(string word : words) 
            for(int i=0; i<n; i++) 
                freq[i][word[i] - 'a']++;
 
        return numWays(n, target, 0, 0, freq, dp);
    }

    int numWays(int n, string& target, int index, int tIndex, vector<vector<ll>>& freq, vector<vector<ll>>& dp) {
        if(tIndex == target.size()) return 1;
        if(index == n) return 0;
        if(dp[index][tIndex] != -1) return dp[index][tIndex];
        
        ll choose = ((freq[index][target[tIndex] - 'a'] % mod) * (numWays(n, target, index+1, tIndex+1, freq, dp) % mod)) % mod;
        ll notChoose = numWays(n, target, index+1, tIndex, freq, dp) % mod;

        return dp[index][tIndex] = ((choose) % mod + (notChoose) % mod) % mod;
    }
};