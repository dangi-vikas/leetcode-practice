class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> adj[n];
        vector<int> dist(n);
        int ans = 1;

        for(int i=1; i<n; i++)
            adj[parent[i]].push_back(i);

        dfs(adj, 0, s, ans, dist);

        return ans;
    }

    void dfs(vector<int> adj[], int src, string& s, int& ans, vector<int>& dist) {
        dist[src] = 1;

        for(auto nbr : adj[src]) {
            dfs(adj, nbr, s, ans, dist);

            if(s[src] != s[nbr]) {
                ans = max(ans, dist[src] + dist[nbr]);
                dist[src] = max(dist[src], dist[nbr]+1);
            }
        }
    }
};