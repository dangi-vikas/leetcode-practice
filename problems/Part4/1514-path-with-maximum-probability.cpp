class Solution {
    double mod = 1e - 5;

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adjList(n);
        double maxProb = DBL_MIN, currProb = 1.0;
        vector<bool> visited(n);
        
        for(int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        dfs(adjList, start, end, maxProb, currProb, visited);
        
        return maxProb;
    }
    
    void dfs(vector<vector<pair<int, double>>>& adjList, int start, int end, double& maxProb, double currProb, vector<bool>& visited) {
        if(currProb <= mod) return;

        if(start == end) {
            maxProb = max(maxProb, currProb);
            return;
        }
        
        visited[start] = true;

        for(auto nbr : adjList[start]) {
            int node = nbr.first;
            double prob = nbr.second;
            
            if(!visited[node] && currProb * prob >= maxProb)
                dfs(adjList, node, end, maxProb, currProb * prob, visited);
        }
        
        visited[start] = false;
    }
};