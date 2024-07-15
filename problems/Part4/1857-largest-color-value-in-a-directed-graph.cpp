class Solution {
public:

  int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int k = 26;
        vector<int> indegrees(n, 0);
        vector<vector<int>> adjList(n, vector<int>());
        unordered_set<int> zeroIndegree;
        vector<vector<int>> counts(n, vector<int>(k, 0));
        int maxCount = 0;
        int visited = 0;
        
        for(vector<int>& edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            adjList[src].push_back(dst);
            indegrees[dst]++;
        }
        
        for(int i=0; i<n; i++) 
            if (indegrees[i] == 0) 
                zeroIndegree.insert(i);
            
        for(int i=0; i<n; i++) 
            counts[i][colors[i] - 'a']++;
        
        while(!zeroIndegree.empty()) {
            int src = *zeroIndegree.begin();
            zeroIndegree.erase(src);
            visited++;

            for(int dst : adjList[src]) {
                for(int i=0; i<k; i++) 
                    counts[dst][i] = max(counts[dst][i], counts[src][i] + (colors[dst] - 'a' == i ? 1 : 0));
                
                indegrees[dst]--;

                if (indegrees[dst] == 0) 
                    zeroIndegree.insert(dst);
            }

            maxCount = max(maxCount, *max_element(counts[src].begin(), counts[src].end()));
        }
        
        return visited == n ? maxCount : -1;
    }

};