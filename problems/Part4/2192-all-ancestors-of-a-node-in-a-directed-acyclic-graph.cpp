class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), directChild(n);
        
        for(auto& e : edges) 
            directChild[e[0]].push_back(e[1]);
        
        for(int i=0; i<n; i++) 
            dfs(i, i, ans, directChild);
        
        return ans;
    }

private:
    void dfs(int x, int curr, vector<vector<int>>& ans, vector<vector<int>>& directChild) {
        for(int child : directChild[curr]) {
            if(ans[child].empty() || ans[child].back() != x) {
                ans[child].push_back(x);
                dfs(x, child, ans, directChild);
            }
        }
    }
};
