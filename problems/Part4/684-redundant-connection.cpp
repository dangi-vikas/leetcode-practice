class Solution {
    vector<int> parents;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents = vector<int>(n+1);
        
        for(int i=0; i<n; i++) parents[i] = i;
        
        for(auto edge : edges) {
            if(findNode(edge[0]) == findNode(edge[1])) return edge;
            unionNode(edge[0], edge[1]);
        }
        
        return {};
    }
    
    int findNode(int node) {
        while(parents[node] != node) 
            node = parents[node];
        
        return node;
    }
    
    void unionNode(int i, int j) {
        int iRoot = findNode(i);
        int jRoot = findNode(j);
            
        if(iRoot != jRoot)
            parents[jRoot] = iRoot;
    }
};