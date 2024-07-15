class Solution {
    static bool comparator(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        if(n == 0) return 0;
        
        sort(envelopes.begin(), envelopes.end(), comparator);
        
        int i, j;
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        
        for(i=1; i<n; i++) {
            if(envelopes[i][1] > dp.back())
                dp.push_back(envelopes[i][1]);
            
            else {
                j = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
                dp[j] = envelopes[i][1]; 
            }
        }
        
        return dp.size();
    }
};