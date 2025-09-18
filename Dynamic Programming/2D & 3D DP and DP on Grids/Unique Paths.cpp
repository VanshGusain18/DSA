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