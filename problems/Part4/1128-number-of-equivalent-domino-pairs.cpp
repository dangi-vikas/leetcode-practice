class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> counts(100);
        int ans = 0;
        
        for (vector<int> d : dominoes) {
            int up = d[0] < d[1] ? d[0] : d[1]; 
			int down = d[0] < d[1] ? d[1] : d[0];
            
            ans += counts[up * 10 + down]++;
        }

        return ans;
    }
};