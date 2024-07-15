class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                ans.push_back({i, j, abs(i-rCenter) + abs(j-cCenter)});
        
        sort(ans.begin(), ans.end(), [](vector<int> &c1, vector<int> &c2){ return c1[2]<c2[2]; });
        
        for(vector<int> &v : ans) v.pop_back();
        
        return ans;
    }
};