class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return mostPoints(questions, 0, questions.size(), dp);
    }

    long long mostPoints(vector<vector<int>>& questions, int i, int n, vector<long long>& dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        long long maxPoints = 0;

        maxPoints = max(maxPoints, mostPoints(questions, i+1, n, dp));
        maxPoints = max(maxPoints, questions[i][0] + mostPoints(questions, i+questions[i][1]+1, n, dp));

        return dp[i] = maxPoints; 
    }
};