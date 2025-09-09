// Recursive Apprch

class Solution
{
public:
    int fn(int n, vector<int> &height)
    {
        if (n == 0)
            return 0;
        int left = fn(n - 1, height) + abs(height[n] - height[n - 1]);
        int right = INT_MAX;
        if (n > 1)
        {
            right = fn(n - 2, height) + abs(height[n] - height[n - 2]);
        }
        return min(left, right);
    }

    int minCost(vector<int> &height)
    {
        // Code here
        return fn(height.size() - 1, height);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(int n, vector<int> &height, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int left = fn(n - 1, height, dp) + abs(height[n] - height[n - 1]);
        int right = INT_MAX;
        if (n > 1)
        {
            right = fn(n - 2, height, dp) + abs(height[n] - height[n - 2]);
        }
        return dp[n] = min(left, right);
    }

    int minCost(vector<int> &height)
    {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return fn(n - 1, height, dp);
    }
};

// Tabulation Approch

class Solution
{
public:
    int minCost(vector<int> &height)
    {
        // Code here
        int n = height.size();
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(height[0] - height[1]);
        for (int i = 2; i < n; i++)
        {
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(left, right);
        }
        return dp[n - 1];
    }
};

// Optimal Approch

class Solution
{
public:
    int minCost(vector<int> &height)
    {
        // Code here
        int n = height.size();
        if (n == 1)
            return 0;
        int prev2 = 0;
        int prev = abs(height[0] - height[1]);
        for (int i = 2; i < n; i++)
        {
            int left = prev + abs(height[i] - height[i - 1]);
            int right = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};