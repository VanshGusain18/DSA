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