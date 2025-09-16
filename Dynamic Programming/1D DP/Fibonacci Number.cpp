// Recursive Approch

class Solution
{
public:
    int fib(int n)
    {
        if (n == 1 || n == 0)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fn(n - 1, dp) + fn(n - 2, dp);
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fn(n, dp);
    }
};

// Tabulation Approch

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
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
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int prev = 1, prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};