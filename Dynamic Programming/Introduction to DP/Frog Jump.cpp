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