class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> scores;
        int n = score.size();
        vector<string> ans(n);
        
        for(int i=0; i<n; i++)
            scores.push({score[i], i});
        
        int j = 0;
        while(!scores.empty()){
            int index = scores.top().second;

            if(j == 0) ans[index] = "Gold Medal";
            else if(j == 1) ans[index] = "Silver Medal";
            else if(j == 2) ans[index] = "Bronze Medal";
            else ans[index] = to_string(j + 1);

            scores.pop(); j++;
        }

        return ans;
    }
};