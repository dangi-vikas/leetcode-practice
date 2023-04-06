class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int island = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 0 && isClosedIsland(grid, i, j)) {
                    island++;
                }
            }
        }

        return island;
    }

    bool isClosedIsland(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size())
            return false;
        
        if (grid[row][col] == 1 || grid[row][col] == -1) return true;

        grid[row][col] = -1;

        bool isLeftClosed = isClosedIsland(grid, row, col - 1);
        bool isRightClosed = isClosedIsland(grid, row, col + 1);
        bool isTopClosed = isClosedIsland(grid, row + 1, col);
        bool isBottomClosed = isClosedIsland(grid, row - 1, col);

        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }
};