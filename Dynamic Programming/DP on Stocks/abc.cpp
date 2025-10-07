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