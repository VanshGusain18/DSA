// Recursive Approch

class Solution
{
public:
    int fn(vector<int> &prices, int i, int buy)
    {
        if (i == prices.size())
            return 0;
        if (buy)
        {
            int take = -prices[i] + fn(prices, i + 1, 0);
            int notTake = fn(prices, i + 1, 1);
            return max(take, notTake);
        }
        else
        {
            int take = prices[i] + fn(prices, i + 1, 1);
            int notTake = fn(prices, i + 1, 0);
            return max(take, notTake);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return fn(prices, 0, 1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &prices, vector<vector<int>> dp, int i, int buy)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy)
        {
            int take = -prices[i] + fn(prices, dp, i + 1, 0);
            int notTake = fn(prices, dp, i + 1, 1);
            return dp[i][buy] = max(take, notTake);
        }
        else
        {
            int take = prices[i] + fn(prices, dp, i + 1, 1);
            int notTake = fn(prices, dp, i + 1, 0);
            return dp[i][buy] = max(take, notTake);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fn(prices, dp, 0, 1);
    }
};

// Tabulation Approch

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    int take = -prices[i] + dp[i + 1][0];
                    int notTake = dp[i + 1][1];
                    dp[i][buy] = max(take, notTake);
                }
                else
                {
                    int take = prices[i] + dp[i + 1][1];
                    int notTake = dp[i + 1][0];
                    dp[i][buy] = max(take, notTake);
                }
            }
        }
        return dp[0][1];
    }
};

// Tabulation Approch

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
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        dp[n][0][0] = 0;
        dp[n][0][1] = 0;
        dp[n][0][2] = 0;
        dp[n][1][0] = 0;
        dp[n][1][1] = 0;
        dp[n][1][2] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 1; k < 3; k++)
                {
                    if (j)
                    {
                        int take = -prices[i] + dp[i + 1][!j][k];
                        int notTake = dp[i + 1][j][k];
                        dp[i][j][k] = max(take, notTake);
                    }
                    else
                    {
                        int take = prices[i] + dp[i + 1][!j][k - 1];
                        int notTake = dp[i + 1][j][k];
                        dp[i][j][k] = max(take, notTake);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};