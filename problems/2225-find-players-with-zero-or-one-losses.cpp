class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loses;
        vector<vector<int>> ans(2);
        
        for(vector<int> match : matches) {
            if(loses.find(match[0]) == loses.end()) loses[match[0]] = 0;
            loses[match[1]]++;
        }
        
        for(auto [player, lose] : loses) {
            if(lose == 0) ans[0].push_back(player);
            if(lose == 1) ans[1].push_back(player);
        }
        
        return ans;
    }
};