class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<int> dp(1001, 0);
        
        for(auto it:allowed){
            int curr = 100 * (it[0]-'A') + 10*(it[1]-'A') + it[2]-'A';   
            dp[curr] = 1;
        }
        
        return pyramidTransitionRec(bottom, dp, "");
    }
    
    bool pyramidTransitionRec(string& bottom, vector<int>& dp, string next){
        if(bottom.size() == 1) return true;
        if(next.size() == bottom.size() - 1)
            return pyramidTransitionRec(next, dp, "");  
        
        for(int j=0; j<7; j++){
            if(dp[100 * (bottom[next.size()]-'A') + 10*(bottom[next.size() + 1]-'A') + j]){
                next.push_back('A' + j);
                bool z = pyramidTransitionRec(bottom, dp, next);
                if(z) return true;
                next.pop_back();
            }
        }
        
        return false;
    }
};