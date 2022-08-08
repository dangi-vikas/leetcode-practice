class Solution {
    unordered_map<int, int> dp;
    
public:
    int findIntegers(int n) {
        return findIntegersRec(n);
    }
    
    int findIntegersRec(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp.find(n) != dp.end()) return dp[n];
        
        int powOf2 = log2(n);
        int leftout = min(pow(2, powOf2-1)-1, n - pow(2, powOf2));
        
        return dp[n] = findIntegersRec(pow(2, powOf2) - 1) + findIntegersRec(leftout); 
    }
};