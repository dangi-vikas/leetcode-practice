class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        vector<unordered_map<int, int>> dp(2020);
        int ans = noOfWays(0, INT_MIN, arr1, arr2, dp); 

        return (ans != INT_MAX) ? ans : -1;    
    }

    int noOfWays(int ind, int prev, vector<int> &arr1, vector<int>& arr2, vector<unordered_map<int, int>>& dp) {
        if(ind >= arr1.size()) return 0;
        if(dp[ind].find(prev) != dp[ind].end()) return dp[ind][prev];

        int notChoose = INT_MAX, choose = INT_MAX;

        if(arr1[ind] > prev) notChoose = noOfWays(ind+1, arr1[ind], arr1, arr2, dp);
        
        int replaceInd = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        
        if(replaceInd != arr2.size())
            choose = noOfWays(ind+1, arr2[replaceInd], arr1, arr2, dp);

        if(choose == INT_MAX) return dp[ind][prev] = notChoose;
        return dp[ind][prev] = min(notChoose,choose+1);
    }
};