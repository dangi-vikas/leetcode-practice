// topological sort

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        
        //adjacency matrix for directed graph
        for(int i=0; i<n; i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> ans;

        //if cycle is present 
        if(isCycle(adj, numCourses)) return ans;
        
        stack<int> st;
        vector<bool> visited(numCourses, false);
        
        //visiting the vertices
        for(int i=0; i<numCourses; i++)
            if(!visited[i])
                dfs(adj, i, visited, st);
        
        //reversing the order and storing in the ans vector
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
    
    //dfs to visit the vertices
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& visited, stack<int>& st){
        visited[curr] = true;
        
        for(int i=0; i<adj[curr].size(); i++)
            if(!visited[adj[curr][i]])
                dfs(adj, adj[curr][i], visited, st);
        
        st.push(curr);
    }
    
    //cycle detection 
    bool isCycle(vector<vector<int>> adj, int& numCourses){
        vector<int> visited(numCourses, 0);
        
        for(int i=0; i<numCourses; i++)
            if(!visited[i])
                if(isCycleRec(adj, visited, i))
                    return true;
        
        return false;
    }
    
    bool isCycleRec(vector<vector<int>>& adj, vector<int>& visited, int curr){
        if(visited[curr] == 1) return true;             //if curr is already visited 
        if(visited[curr] == 2) return false;
        
        visited[curr] = 1;              //mark current vertex as visited
        for(int i=0; i<adj[curr].size(); i++)
            if(isCycleRec(adj, visited, adj[curr][i]))
                return true;
        
        visited[curr] = 2;              //mark as processed
        return false;
    }
};