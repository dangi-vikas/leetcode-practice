class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        
        int perimeter = 0;
        for(int matchstick : matchsticks) perimeter += matchstick; 
        
        if(perimeter % 4) return false;
        
        int side = perimeter / 4;
        vector<bool> seen(matchsticks.size(), false);
        
        return makesquareRec(0, side, 0, matchsticks, 0, seen);
    }
    
    bool makesquareRec(int curr, int& side, int partitionNum, vector<int>& matchsticks, int index, vector<bool>& seen){
        if(partitionNum == 3) return true;
        
        if(curr == side) return makesquareRec(0,side,partitionNum+1,matchsticks,0,seen);
        
        for(int i=index; i<matchsticks.size(); i++){
            if(!seen[i]){
                seen[i] = true;
                
            if(makesquareRec(curr+matchsticks[i],side,partitionNum,matchsticks,i+1,seen))
                    return true;
                
                seen[i] = false;
            }
        }
        
        return false;
    }
};