class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adjList;
        
        for(auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if(curr == destination) return true;
            for(auto& node : adjList[curr]) {
                if(!visited[node]) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
        
        return false;
    }
};
