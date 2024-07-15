class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start = 0;
        const int n = s.size();
        vector<vector<int>> ans;
        
        for(int i=1; i<n; i++) {
            if(s[i - 1] != s[i]) {
                if(i - start >= 3) ans.push_back({start, i - 1});
                start = i;
            }
        }
        
        if(n - start >= 3) ans.push_back({start, n - 1});
        
        return ans;
    }
};
