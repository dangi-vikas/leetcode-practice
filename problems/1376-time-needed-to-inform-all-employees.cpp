class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        vector<int> dp(n);

        for(int i=0; i<n; i++) 
            if(manager[i] != -1)
                adjList[manager[i]].push_back(i);

        dfs(headID, manager, informTime, adjList, dp);

        return dp[headID];
    }

    int dfs(int src, vector<int>& manager, vector<int>& informTime, vector<vector<int>>& adjList, vector<int>& dp) {
        int ans = 0;

        for(int nbr : adjList[src]) {
            dfs(nbr, manager, informTime, adjList, dp);
            dp[src] = max(dp[src], informTime[src] + dp[nbr]);
        }

        return dp[src];
    }
};