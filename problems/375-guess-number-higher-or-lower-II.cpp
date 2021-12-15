class Solution { 
    unordered_map<int, unordered_map<int, int>> dp;
    
public:
   
    int getMoneyAmount(int n) {
        return getMoneyAmountRec(1, n);
    }
    
    int getMoneyAmountRec(int low, int high) {
        
        if(low >= high) return 0;
        if(dp[low].count(high)) return dp[low][high];
        
        int ans = INT_MAX;
        
        for(int i = low ; i <= high ; i++) {
            int temp = i + max(getMoneyAmountRec(low, i - 1), getMoneyAmountRec(i + 1, high));
            ans = min(ans, temp);
        }
        
        return dp[low][high] = ans;
    }
};