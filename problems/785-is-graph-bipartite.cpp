class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1, -1);
        
        for(int i=0; i<n; i++) 
            if(color[i] == -1) 
                if(!dfs(graph, i, color)) return false;
        
        return true;     
    }
    
    bool dfs(vector<vector<int>>& graph, int& src, vector<int>& color) {
        color[src] = 1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int s = q.front();
            q.pop();
            
            for(auto neighbor : graph[s]) {
                if(color[neighbor] == -1) {
                    color[neighbor] = 1 - color[s];
                    q.push(neighbor);
                }
                
                else if(color[neighbor] == color[s])
                    return false;
            }
        }
        
        return true;
    }
};