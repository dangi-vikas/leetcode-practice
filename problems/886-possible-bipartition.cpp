class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n+1);
        
        for(int i=0; i<dislikes.size(); i++) {
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> colors(n+1, -1); 
        
        for(int i=1; i<=n; i++)
            if(colors[i] == -1) 
                if(!isBipartite(adjList, n, i, colors))
                    return false;
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adjList, int n, int index, vector<int>& colors) {
        queue<int> q;
        
        q.push(index);
        colors[index] = 1;
        
        while(!q.empty()) {
            int src = q.front();
            q.pop();
            
            for(int dst : adjList[src]) {
                if(colors[dst] == colors[src])
                    return false;
                
                if(colors[dst] == -1) {
                    colors[dst] = 1 - colors[src];
                    q.push(dst);
                }
            }
        }
        
        return true;
    }
};