class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n);
        map<int, int> check; 
        
        for (int i = 0; i < n; i++) 
            check[intervals[i][0]] = i;
        
        for (int i = 0; i < n; i++) {
            auto it = check.lower_bound(intervals[i][1]);
            
            if (it != check.end()) 
                ans[i] = it->second;
                
            else ans[i] = -1;
        }
        
        return ans;
    }
};