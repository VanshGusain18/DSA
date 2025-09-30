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
