class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n+1];
        vector<bool> visited(n+1, false);
        queue<int> q;
        int ans = INT_MAX;

        for(int i=0; i<roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        q.push(1);
        visited[1] = true;

        while(!q.empty()) {
            int node = q.front();   
            q.pop();

            for(auto nbr : adj[node]) {
                if(!visited[nbr[0]]) {
                    q.push(nbr[0]);
                    visited[nbr[0]] = true;
                }
            }
        }

        for(int i=0; i<roads.size(); i++) 
            if(visited[roads[i][0]] && visited[roads[i][1]])
                ans = min(ans, roads[i][2]);
        
        return ans;
    }
};