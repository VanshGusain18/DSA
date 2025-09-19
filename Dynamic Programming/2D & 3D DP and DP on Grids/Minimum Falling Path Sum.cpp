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

// Tabulation Approch

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = dp[i - 1][j];
                int uLeft = INT_MAX;
                if (j > 0)
                {
                    uLeft = dp[i - 1][j - 1];
                }
                int uRight = INT_MAX;
                if (j < n - 1)
                {
                    uRight = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + min({up, uLeft, uRight});
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};
