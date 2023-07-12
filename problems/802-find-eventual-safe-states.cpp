class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n);
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<n; i++) {
            for(int j : graph[i]) {
                adjList[j].push_back(i);
                inDegree[i]++;
            }
        }

        for(int i=0; i<n; i++) 
            if(inDegree[i] == 0) q.push(i);

        while(!q.empty()) {
            int src = q.front();
            q.pop();

            ans.push_back(src);

            for(int nbr : adjList[src]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) q.push(nbr);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};