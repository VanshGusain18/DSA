// Better Approch

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            profit = 0;
            for (int j = i; j < prices.size(); j++)
            {
                if (prices[i] < prices[j])
                {
                    profit = prices[j] - prices[i];
                    if (maxProfit < profit)
                    {
                        maxProfit = profit;
                    }
                }
            }
        }
        return maxProfit;
    }
};
