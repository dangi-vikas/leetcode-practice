class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<bool>& visited, int &count) {
        visited[node] = true;  
        count++;
        
        if(edges[node] != -1 && visited[edges[node]] == false)
            dfs(edges, edges[node], visited, count);
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        vector<bool> visited(n, false);
        queue<int> q;
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int v = edges[i]; 
            if(v != -1) indegree[v]++;
        }
        
        for(int i = 0; i < n; i++) 
            if(indegree[i] == 0) q.push(i);
        
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            if(edges[node] != -1) {
                indegree[edges[node]]--;
                
                if(indegree[edges[node]] == 0)
                    q.push(edges[node]);
            }
        }
    
        for(int i = 0; i < n; i++) {
            int count = 0;
            
            if(indegree[i] > 0 && visited[i] == false)
                dfs(edges, i, visited, count);
            
            maxi = max(maxi, count);
        }
        
        return (maxi == 0) ? -1 : maxi;
    }
};