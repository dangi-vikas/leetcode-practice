//Approach 1

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};


//Approach 2

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
		return stoneGameRec(piles, 0, n-1, 1, dp);
    }
    
    int stoneGameRec(vector<int>& piles, int start, int end, bool isAlice, vector<vector<vector<int>>>& dp) {
        if(start == end) return 0;
        
        if(dp[start][end][isAlice] != -1) return dp[start][end][isAlice];
        
        if(isAlice) 
            return dp[start][end][isAlice] = max(
                (piles[start] + stoneGameRec(piles, start+1, end, 0, dp)),
                (piles[end] + stoneGameRec(piles, start, end-1, 0, dp)));
        
        else return dp[start][end][isAlice] = min((stoneGameRec(piles, start+1, end, 1, dp)),
                                                  (stoneGameRec(piles, start, end-1, 1, dp)));
    }
};