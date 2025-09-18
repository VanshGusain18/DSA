// Recursive Approch

class Solution
{
public:
    int fn(int r, int c)
    {
        if (r == 0 && c == 0)
            return 1;
        if (r < 0 || c < 0)
            return 0;
        int up = fn(r - 1, c);
        int right = fn(r, c - 1);
        return up + right;
    }

    int uniquePaths(int m, int n)
    {
        return fn(m - 1, n - 1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(int r, int c, vector<vector<int>> &dp)
    {
        if (r == 0 && c == 0)
            return 1;
        if (r < 0 || c < 0)
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];
        int up = fn(r - 1, c, dp);
        int right = fn(r, c - 1, dp);
        return dp[r][c] = up + right;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(m - 1, n - 1, dp);
    }
};

// Tabulation Approch

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
