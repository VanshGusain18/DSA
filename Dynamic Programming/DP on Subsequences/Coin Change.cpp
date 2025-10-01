// Brute Approch

class Solution
{
public:
    void fn(vector<int> &coins, int amount, int n, int temp, int &mini)
    {
        if (amount == 0)
        {
            mini = min(temp, mini);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= amount)
            {
                fn(coins, amount - coins[i], n, temp + 1, mini);
            }
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int mini = INT_MAX;
        fn(coins, amount, n, 0, mini);
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &coins, int amount, vector<vector<int>> &dp, int idx)
    {
        if (idx == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTaken = fn(coins, amount, dp, idx - 1);
        int taken = 1e9;
        if (coins[idx] <= amount)
            taken = 1 + fn(coins, amount - coins[idx], dp, idx);
        return dp[idx][amount] = min(notTaken, taken);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int mini = fn(coins, amount, dp, n - 1);
        return (mini >= 1e9) ? -1 : mini;
    }
};

// Tabulation Method

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notTaken = dp[i - 1][j];
                int taken = 1e9;
                if (coins[i] <= j)
                {
                    taken = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(taken, notTaken);
            }
        }
        int mini = dp[n - 1][amount];
        if (mini == 1e9)
            return -1;
        return mini;
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &val, vector<int> &wt, vector<vector<int>> &dp, int capacity, int idx)
    {
        if (capacity == 0)
            return 0;
        if (idx == 0)
        {
            return (capacity / wt[0]) * val[0];
        }
        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];
        int notTaken = fn(val, wt, dp, capacity, idx - 1);
        int taken = -1e9;
        if (wt[idx] <= capacity)
        {
            taken = val[idx] + fn(val, wt, dp, capacity - wt[idx], idx);
        }
        return dp[idx][capacity] = max(notTaken, taken);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return fn(val, wt, dp, capacity, n - 1);
    }
};
