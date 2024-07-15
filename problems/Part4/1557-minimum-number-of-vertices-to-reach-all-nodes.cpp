class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> adj;
        vector<int> ans;
        
        for(vector<int>& edge : edges) adj.insert(edge[1]);
        
        for(int i=0; i<n; i++) 
            if (adj.find(i) == adj.end()) 
                ans.push_back(i);
        
        return ans;
    }
};