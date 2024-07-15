class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int untouched = 0;
        unordered_map<int, int> endIndex;
        
        for(auto row : wall) {
            int end = 0;
            
            for(int brick=0; brick<row.size()-1; brick++) {
                end += row[brick];
                endIndex[end]++;
                untouched = max(untouched, endIndex[end]);
            }
        }
        
        return wall.size() - untouched;
    }
};