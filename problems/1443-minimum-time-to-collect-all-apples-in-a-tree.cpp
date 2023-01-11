class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1, adj, hasApple);
    }

    int dfs(int src, int parent, vector<int> adj[], vector<bool>& hasApple) {
        int ans = 0;

        for(auto nbr : adj[src]) {
            if(nbr != parent) {
                int time = dfs(nbr, src, adj, hasApple);

                if(time > 0 || hasApple[nbr]) 
                    ans += time + 2;
            }
        }

        return ans;
    }
};