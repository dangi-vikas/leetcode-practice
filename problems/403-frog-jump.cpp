class Solution {
    unordered_map<int, int> um;
    
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int i=0; i<n; i++)
            um[stones[i]] = i;
        
        return dfs(stones, 0, 0, dp);
    }
    
    bool dfs(vector<int>& stones, int i, int k, vector<vector<int>> &dp) {
        if(i == stones.size()-1) return true;
        if(dp[i][k] != -1) return dp[i][k];
        
        bool val = false;
        
        if(i == 0) { 
            if(um.count(stones[i]+k+1))
                val = val || dfs(stones, um[stones[i]+k+1], k+1, dp);
        }
        
        else {
            if(um.count(stones[i]+k))
                val = val || dfs(stones, um[stones[i]+k], k, dp);
            
            if(um.count(stones[i]+k+1))
                val = val || dfs(stones, um[stones[i]+k+1], k+1, dp);
           
            if(um.count(stones[i]+k-1) && um[stones[i]+k-1] > i)
                val = val || dfs(stones, um[stones[i]+k-1], k-1, dp);  
        }
        
        return dp[i][k] = val;
    }
};