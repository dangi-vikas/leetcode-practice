class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(string str : strs){
            vector<int> counts = count(str);
            
            for(int zero=m; zero>=counts[0]; zero--)
                for(int one=n; one>=counts[1]; one--)
                    dp[zero][one] = max((dp[zero-counts[0]][one-counts[1]]+1), dp[zero][one]);
        }
        
        return dp[m][n];
    }
    
    vector<int> count(string str){
        vector<int> counts(2);
        for(char ch: str) counts[ch - '0']++;
        return counts;
    }
};