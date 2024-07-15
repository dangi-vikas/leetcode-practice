class Solution {
public:
    int ans = 0;
    int mod = 1e9 + 7;
 
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        if(profit.size() == 0) return 0;

        int len = profit.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>> (minProfit+1, vector<int> (n+1, -1)));

        return profitabkeSchemes(len-1, minProfit, n, group, profit, dp);
    }

    int profitabkeSchemes(int index, int target, int remainingPeople, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        if(index < 0) return (target > 0) ? 0 : 1;
        if(target < 0) target = 0;
        if(dp[index][target][remainingPeople] != -1) return dp[index][target][remainingPeople];

        int pick = 0;

        if(remainingPeople >= group[index]) 
            pick = profitabkeSchemes(index-1, target - profit[index], remainingPeople - group[index], group, profit, dp);
        int notPick = profitabkeSchemes(index-1, target, remainingPeople, group, profit, dp);

        return dp[index][target][remainingPeople] = (pick % mod + notPick % mod) % mod;
    }
};