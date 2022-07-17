class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<int> next(m, 0);
        
        for(int i=n-1; i>=0; i--) {
            vector<int> curr(m, 0);
            
            for(int j=m-1; j>=0; j--) {
                if(i == n-1 && j == m-1) 
                    curr[j] = min(0, dungeon[i][j]);
                
                else if(i == n-1)
                    curr[j] = min(0, dungeon[i][j] + curr[j+1]);
                
                else if(j == m-1)
                    curr[j] = min(0, dungeon[i][j] + next[j]);
                
                else curr[j] = min(0, dungeon[i][j] + max(next[j], curr[j+1]));
            }
            
            next = curr;
        }
                                    
        return abs(next[0]) + 1;
    }
};