class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> container;

        dfs(graph, ans, 0, container);

        return ans;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, int src, vector<int>& container) {
        container.push_back(src);

        if(src ==  graph.size() - 1) {
            ans.push_back(container);
            return;
        }

        for(auto nbr : graph[src]) {
            dfs(graph, ans, nbr, container);
            container.pop_back();
        }
    }
};