class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 0, right = cells.size(), ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (traverse(cells, row, col, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
    bool traverse(vector<vector<int>> &cells, int row, int col, int mid)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < mid; i++)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        vector<vector<int>> check = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (int j = 0; j < col; j++)
        {
            if (grid[0][j] == 0)
            {
                q.push({0, j});
                grid[0][j] = 1;
            }
        }
        while (!q.empty())
        {
            int currow = q.front().first;
            int curcol = q.front().second;
            q.pop();
            if (currow == row - 1)
                return true;
            for (int i = 0; i < 4; i++)
            {
                int nrow = currow + check[i][0];
                int ncol = curcol + check[i][1];
                if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && !grid[nrow][ncol])
                {
                    grid[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return false;
    }
};