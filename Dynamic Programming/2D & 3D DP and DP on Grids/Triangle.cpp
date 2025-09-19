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
        if (i < 0 || j < 0 || i < j)
        {
            return INT_MAX;
        }
        int up = fn(grid, i - 1, j);
        int left = fn(grid, i - 1, j - 1);
        return grid[i][j] + min(up, left);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, fn(triangle, n - 1, i));
        }
        return mini;
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
        if (i < 0 || j < 0 || i < j)
        {
            return INT_MAX;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = fn(grid, dp, i - 1, j);
        int left = fn(grid, dp, i - 1, j - 1);
        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, fn(triangle, dp, n - 1, i));
        }
        return mini;
    }
};