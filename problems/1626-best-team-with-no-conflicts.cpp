class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> teams;
        int n = scores.size();
        vector<int> dp(n+1);

        for(int i=0; i<n; i++)
            teams.push_back({ages[i], scores[i]});
        
        sort(teams.begin(), teams.end());
        dp[0] = teams[0].second;

        for(int i=1; i<n; i++){
            dp[i] = teams[i].second;

            for(int j=0; j<i; j++) 
                if(teams[i].second >= teams[j].second) 
                    dp[i] = max(dp[j] + teams[i].second, dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};