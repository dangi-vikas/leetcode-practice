class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        
        for(int i=0; i<richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        
        vector<int> ans(n, INT_MAX);
        queue<int> q;

        for(int i=0; i<n; i++) {
            if(indeg[i] == 0) q.push(i);
            ans[i]=i;    
        }
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            for(int i=0; i<adj[x].size(); i++) {
                int u = adj[x][i];
                indeg[u]--;
                
                if(quiet[ans[x]] < quiet[ans[u]])
                    ans[u] = ans[x];
                
                if(indeg[u] == 0) q.push(u);
            }
        }
        
        return ans;
    }
};