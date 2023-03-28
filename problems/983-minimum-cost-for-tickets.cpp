class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> travel = {1, 7, 30};
        vector<int> dp(n, -1);

        return minCostTickets(days, travel, costs, 0, dp);

    }

    int minCostTickets(vector<int>& days, vector<int>& travel, vector<int>& costs, int i, vector<int>& dp) {
        if(i == days.size()) return 0;
    
        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int t=0; t<3; t++) {
            int nextDay = findNextDay(days, i, travel[t]);
            int currCost = costs[t] + minCostTickets(days, travel, costs, nextDay, dp);

            minCost = min(minCost, currCost);
        }

        return dp[i] = minCost;
    }

    int findNextDay(vector<int>& days, int currIdx, int daysLimit) {
        int maxDay = days[currIdx] + daysLimit - 1;

        for(int i=currIdx+1; i<days.size(); i++) 
            if(days[i] > maxDay) return i;
        

        return days.size();
    }
};