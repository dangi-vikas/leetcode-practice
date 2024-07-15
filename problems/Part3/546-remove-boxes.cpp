class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        if(boxes.size() == 0) return 0;
        
        int n =  boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        
        return dfs(dp, boxes, 0, n-1, 0);
    }
    
    int dfs(vector<vector<vector<int>>>& dp, vector<int>& boxes, int left, int right, int streak) {
        if(left > right) return 0;
        else if(left == right) return (streak+1) * (streak+1);
        else if(dp[left][right][streak]) return dp[left][right][streak];
        else  {
            int mx = dfs(dp, boxes, left+1, right, 0) + ((streak+1) * (streak+1));
            
            for(int i=left+1; i<=right; i++) {
                if(boxes[left] == boxes[i])
                    mx = max(mx, dfs(dp, boxes, left+1, i-1, 0) + dfs(dp, boxes, i, right, streak+1));
            }
            
            dp[left][right][streak] = mx;
            
            return mx;
        }
        
        
    }
};