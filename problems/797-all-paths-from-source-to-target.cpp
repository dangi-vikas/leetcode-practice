class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(graph, path, ans, 0);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans, int src) {
        path.push_back(src);
        
        if(src == graph.size() - 1) 
            ans.push_back(path); 
        
        else 
            for(int neighbor : graph[src]) dfs(graph, path, ans, neighbor);
        
        path.pop_back(); 
    }
};