class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> safe;
        vector<int> ans;
        
        for(int i=0; i<graph.size(); i++) 
            if(dfs(graph, safe, i)) 
                ans.push_back(i);
        
        return ans;
    }
    
    bool dfs(vector<vector<int>>& graph, unordered_map<int, bool>& safe, int& src) {
        if(safe.find(src) != safe.end()) 
            return safe[src];
        
        safe[src] = false;
        
        for(auto neighbour : graph[src]) 
            if(!dfs(graph, safe, neighbour))
               return safe[src];
               
        safe[src] = true;
        return safe[src];
    }
};