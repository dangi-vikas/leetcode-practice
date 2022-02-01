class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector(n,-1));

        return longestPalindromeSubseqRec(s, dp, 0, n-1);
    }
    
    int longestPalindromeSubseqRec(string &s, vector<vector<int>> &dp, int left, int right) {
    
        if(left > right) return 0;
        if(left == right) return 1;
        
        if(dp[left][right] != -1) return dp[left][right];
        else if(s[left] == s[right]) 
            dp[left][right] =  2 + longestPalindromeSubseqRec(s, dp, left+1, right-1);
        else 
            dp[left][right] =  max(longestPalindromeSubseqRec(s, dp, left+1, right), longestPalindromeSubseqRec(s, dp, left, right-1)); 

        return dp[left][right];
    }
};