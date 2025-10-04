// Recursive Approch

class Solution
{
public:
    int fn(vector<int> &prices, int i, int buy, int curr)
    {
        if (i == prices.size() || curr == 0)
            return 0;
        if (buy)
        {
            int take = -prices[i] + fn(prices, i + 1, 0, curr);
            int notTake = fn(prices, i + 1, 1, curr);
            return max(take, notTake);
        }
        else
        {
            int take = prices[i] + fn(prices, i + 1, 1, curr - 1);
            int notTake = fn(prices, i + 1, 0, curr);
            return max(take, notTake);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return fn(prices, 0, 1, 2);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &prices, vector<vector<vector<int>>> &dp, int i, int buy, int curr)
    {
        if (i == prices.size() || curr == 0)
            return 0;
        if (dp[i][buy][curr] != -1)
            return dp[i][buy][curr];
        if (buy)
        {
            int take = -prices[i] + fn(prices, dp, i + 1, 0, curr);
            int notTake = fn(prices, dp, i + 1, 1, curr);
            return dp[i][buy][curr] = max(take, notTake);
        }
        else
        {
            int take = prices[i] + fn(prices, dp, i + 1, 1, curr - 1);
            int notTake = fn(prices, dp, i + 1, 0, curr);
            return dp[i][buy][curr] = max(take, notTake);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fn(prices, dp, 0, 1, 2);
    }
};