class Solution {
    vector<bool> visited;
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size());
        visited[0] = true;
        
        dfs(rooms, 0);
        
        for(bool isVisited : visited) if(!isVisited) return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, int index) {
        for(int i : rooms[index]) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(rooms, i);
            }
        } 
    }
};