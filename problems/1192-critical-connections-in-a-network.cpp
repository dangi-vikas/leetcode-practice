class Solution {
    int timer = 1;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> visited(n);
        vector<int> timeIn(n), low(n);
        vector<vector<int>> bridges;

        for(auto connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        dfs(0, -1, visited, adj, timeIn, low, bridges);

        return bridges;
    }

    void dfs(int node, int parent, vector<int>& visited, vector<int> adj[], vector<int>& timeIn, vector<int>& low, vector<vector<int>>& bridges) {
        visited[node] = 1;
        timeIn[node] = low[node] = timer;
        timer++;

        for(auto nbr : adj[node]) {
            if(nbr == parent) continue;

            if(!visited[nbr]) {
                dfs(nbr, node, visited, adj, timeIn, low, bridges);
                low[node] = min(low[node], low[nbr]);

                if(low[nbr] > timeIn[node])
                    bridges.push_back({nbr, node});
            }

            else low[node] = min(low[node], low[nbr]);
        }
    }
};