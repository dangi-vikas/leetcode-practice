class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        //adjacency matrix for directed graph
        for(int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        vector<int> visited(numCourses, 0);
         
        for(int i=0; i<numCourses; i++)
            
            //if the element is never visited
            if(visited[i] == 0)
                
                //check for cycle
                if(isCycle(adj, visited, i)) return false;
        
        return true;
    }
    
    bool isCycle(vector<vector<int>>& adj, vector<int>& visited, int curr){
        
        //if the current element is always is processing state
        if(visited[curr] == 2) return true;
        
        visited[curr] = 2;
        
        //check for cycle in adjacent element
        for(int i=0; i<adj[curr].size(); i++)
            if(visited[adj[curr][i]] != 1)
                if(isCycle(adj, visited, adj[curr][i]))
                    return true;
        

        //if no cycle is detected mark as processed
        visited[curr] = 1;
        
        return false;
    }
};

//Visited markers:
//1: processed
//2: processing
//3: unvisited