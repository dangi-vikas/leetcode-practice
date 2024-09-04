class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        map<pair<int,int>,int> mp;
        int maxDist = 0;
        
        for(auto it: obstacles) mp[{it[0], it[1]}]++;
        pair<int, int> dir = {0, 1};
        
        for(int i=0; i<commands.size(); i++) {
            int c = commands[i];
            
            if(c == -1) {
                pair<int, int> dir1;
                
                if(dir.first != 0)
                     dir1 = {dir.second * -1 , dir.first * -1};
                else dir1 = {dir.second, dir.first};
                
                dir = dir1;
            }
            
            else if(c == -2) {
                pair<int, int> dir1;
                
                if(dir.first != 0)
                    dir1 = {dir.second, dir.first};
                else dir1 = {dir.second * -1 , dir.first * -1};
                
                dir = dir1;
            }
            
            else {
               for(int i = 1; i <= c; i++){
                   int nx = x + dir.first;
                   int ny = y +  dir.second;
                   
                   if(mp.find({nx, ny}) != mp.end()) break;
                   
                   x = nx;
                   y = ny;
                   
               } 
            }
            
            maxDist = max(1LL*maxDist, ((1LL*x*x + 1LL*y*y)));
        }
        
        return maxDist;
    }
};