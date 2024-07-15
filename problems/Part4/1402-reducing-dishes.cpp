class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        unordered_map<string, int> dp;

        sort(satisfaction.begin(), satisfaction.end());
        int ans = maxSatisfaction(satisfaction, n, 0, 1, dp);

        return (ans >= 0) ? ans : 0;
    }

    int maxSatisfaction(vector<int>& satisfaction, int n, int index, int time, unordered_map<string, int> & dp) {
        if(index >= n) return 0;

        string key = to_string(index) + "$" + to_string(time);

        if(dp.find(key) != dp.end()) return dp[key];

        int mxSatisfaction = INT_MIN;

        int currSatisfactionInc = (satisfaction[index] * time) + maxSatisfaction(satisfaction, n, index+1, time+1, dp);
        int currSatisfactionExc = maxSatisfaction(satisfaction, n, index+1, time, dp);

        mxSatisfaction = max(currSatisfactionInc, currSatisfactionExc);

        return dp[key] = mxSatisfaction;
        
    }
};