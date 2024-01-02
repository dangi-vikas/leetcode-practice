class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> counts;
        
        for(auto i: nums)
            counts[i]++;
        

        while(!counts.empty()) {
            vector<int> temp;
            
            for(auto it = counts.begin(); it != counts.end();) {
                temp.push_back(it->first);
                it->second--;
                
                if(it->second == 0)
                    it = counts.erase(it);
                else it++;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
