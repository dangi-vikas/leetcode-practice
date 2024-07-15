class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int& nodesInComponent, int node) {
        visited[node] = true;
        nodesInComponent++; 

        for(int nbr : adj[node])
            if(!visited[nbr]) dfs(adj, visited, nodesInComponent, nbr);   
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        long long count = 0, rem = n;

        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false); 

        for(int i=0; i<n; i++) {
            int c = 0;

            if(!visited[i]) { 
                dfs(adj, visited, c, i);
                count += (rem-c) * c;
                rem -= c;
            }
        }

        return count;
    }
};



        

