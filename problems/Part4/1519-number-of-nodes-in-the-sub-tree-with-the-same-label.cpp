class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        vector<int> ans(n);
        vector<int> freq(26, 0);

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, adj, labels, ans, freq);

        return ans;
    }

    void dfs(int src, int parent, vector<int> adj[], string& labels, vector<int>& ans, vector<int>& freq) {
        int prevCount = freq[labels[src] - 'a'];
        freq[labels[src] - 'a']++;

        for(auto nbr : adj[src]) {
            if(nbr != parent) {
                dfs(nbr, src, adj, labels, ans, freq);
            }
        }

        ans[src] = freq[labels[src] - 'a'] - prevCount; 
    }
};