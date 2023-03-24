class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        queue<pair<int, int>> q;
        vector<bool> visited(n,false);
        int ans=0;

        for(auto& edge: connections) {
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }

        q.push({0, 0});

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            visited[node.first] = true;
            ans += node.second;

            for(auto &nbr: adj[node.first]){
                if(visited[nbr.first]) continue;
                q.push(nbr);
            }
        }

        return ans;
    }
};