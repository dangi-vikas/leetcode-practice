class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int currRoom = q.front(); 
            q.pop();
            visited[currRoom] = 1;
            
            for(auto key : rooms[currRoom])
                if(!visited[key])
                    q.push(key);
        }

        for(int i=0; i<n; i++)
            if(!visited[i]) return false;
           
        return true;
    }
};
