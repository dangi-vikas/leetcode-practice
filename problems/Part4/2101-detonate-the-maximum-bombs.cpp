class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adjList(n);
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                double d = pow(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2), 0.5);
                if(d <= bombs[i][2]) adjList[i].push_back(j);
            }
        }

        for(int i=0; i<n; i++) {
            vector<bool> visited(n, false);
            ans = max(ans, dfs(i, adjList, visited));
        }

        return ans;
    }

    int dfs(int src, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[src] = true;
        int bombsDetonated = 1;

        for(int nbr : adjList[src]) {
            if(!visited[nbr]) 
                bombsDetonated += dfs(nbr, adjList, visited);
        }

        return bombsDetonated;
    }
};