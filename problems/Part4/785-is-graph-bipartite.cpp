class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++) 
            if(!isColored(0, i, color, graph))
                return false;

        return true;
    }

    bool isColored(int src, int dst, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;

        q.push(dst);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto nbr : graph[node]) {
                if(color[nbr] == -1) {
                    color[nbr] = !color[node];
                    q.push(nbr);
                }

                else if(color[nbr] == color[node]) return false;
            }
        }

        return true;
    }
};