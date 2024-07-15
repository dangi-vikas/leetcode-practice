class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int low = 0, high = 0, mid = 0;
        int count = 0, ans = 0;

        for(int i=0; i<grid.size(); i++) {
            low = 0;
            count = 0;
            high = grid[i].size() - 1;

            while (low <= high) {
                mid = low + ((high - low) >> 1);
                
                if (grid[i][mid] < 0) {
                    count = grid[i].size() - mid;
                    high = mid - 1;
                } 
                
                else low = mid + 1;
            }
            ans += count;
        }
        return ans;
    }
};