// Brute Approch

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

// Optimal Approch

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = prices[0], profit = 0, maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
            }
            else
            {
                profit = prices[i] - min;
                if (maxProfit < profit)
                {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};