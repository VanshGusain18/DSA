// Memoization Approch

class Solution
{
public:
    int fn(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0 || j < 0 || j >= grid.size())
            return INT_MAX;
        if (i == 0)
            return grid[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = fn(grid, dp, i - 1, j);
        int uLeft = fn(grid, dp, i - 1, j - 1);
        int uRight = fn(grid, dp, i - 1, j + 1);
        return dp[i][j] = grid[i][j] + min({up, uLeft, uRight});
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, fn(matrix, dp, n - 1, i));
        }
        return mini;
    }
};