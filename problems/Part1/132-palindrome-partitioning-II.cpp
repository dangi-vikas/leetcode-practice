class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--) {
            int minCost = INT_MAX;
            
            for(int j=i; j<n; j++) {
                if(isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            
            dp[i] = minCost;
        }
        
        return dp[0] - 1;
    }
    
    bool isPalindrome (int start, int end, string& str) {
        while(start < end) {
            if(str[start] != str[end]) return false;
            start++; end--;
        } 
            
        return true;
    }
};