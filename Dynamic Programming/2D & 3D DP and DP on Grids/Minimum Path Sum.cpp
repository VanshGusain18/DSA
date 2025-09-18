// Recursive Approch

class Solution
{
public:
    int fn(vector<vector<int>> &grid, int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return grid[0][0];
        }
        if (i == -1 || j == -1)
        {
            return INT_MAX;
        }
        int up = fn(grid, i - 1, j);
        int left = fn(grid, i, j - 1);
        return grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        return fn(grid, n - 1, m - 1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return grid[0][0];
        }
        if (i == -1 || j == -1)
        {
            return INT_MAX;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = fn(grid, dp, i - 1, j);
        int left = fn(grid, dp, i, j - 1);
        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(grid, dp, n - 1, m - 1);
    }
};