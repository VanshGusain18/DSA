class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int r, int c)
    {
        grid[i][j] = -1;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && grid[nrow][ncol] == 1)
            {
                dfs(grid, nrow, ncol, r, c);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, r, c);
            if (grid[i][c - 1] == 1)
                dfs(grid, i, c - 1, r, c);
        }
        for (int j = 0; j < c; j++)
        {
            if (grid[0][j] == 1)
                dfs(grid, 0, j, r, c);
            if (grid[r - 1][j] == 1)
                dfs(grid, r - 1, j, r, c);
        }
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};
