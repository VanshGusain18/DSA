class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j, int r, int c)
    {
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                dfs(grid, vis, nrow, ncol, r, c);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int cnt = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    dfs(grid, vis, i, j, r, c);
                }
            }
        }
        return cnt;
    }
};
