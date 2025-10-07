// Recursive Approch

class Solution
{
public:
    int fn(vector<int> &prices, int i, int buy, int lock)
    {
        if (i == prices.size())
            return 0;
        if (lock)
        {
            return fn(prices, i + 1, 1, 0);
        }
        if (buy)
        {
            int take = -prices[i] + fn(prices, i + 1, 0, 0);
            int notTake = fn(prices, i + 1, 1, 0);
            return max(take, notTake);
        }
        else
        {
            int take = prices[i] + fn(prices, i + 1, 1, 1);
            int notTake = fn(prices, i + 1, 0, 0);
            return max(take, notTake);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return fn(prices, 0, 1, 0);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &prices, vector<vector<vector<int>>> &dp, int i, int buy, int lock)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][buy][lock] != -1)
            return dp[i][buy][lock];
        if (lock)
        {
            return dp[i][buy][lock] = fn(prices, dp, i + 1, 1, 0);
        }
        if (buy)
        {
            int take = -prices[i] + fn(prices, dp, i + 1, 0, 0);
            int notTake = fn(prices, dp, i + 1, 1, 0);
            return dp[i][buy][lock] = max(take, notTake);
        }
        else
        {
            int take = prices[i] + fn(prices, dp, i + 1, 1, 1);
            int notTake = fn(prices, dp, i + 1, 0, 0);
            return dp[i][buy][lock] = max(take, notTake);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return fn(prices, dp, 0, 1, 0);
    }
};