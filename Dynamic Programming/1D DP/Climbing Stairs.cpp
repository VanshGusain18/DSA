// Recursive Approch

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        int left = climbStairs(n - 1);
        int right = climbStairs(n - 2);
        return left + right;
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int left = fn(n - 1, dp);
        int right = fn(n - 2, dp);
        return dp[n] = left + right;
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return fn(n, dp);
    }
};

// Tabulation Approch

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Optimal Approch

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev2 = 1, prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};