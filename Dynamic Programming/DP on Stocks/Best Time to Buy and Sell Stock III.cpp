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