// Brute Approch

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> lft(n);
        vector<int> rgt(n);
        lft[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                lft[i] = lft[i - 1] + 1;
            }
            else
                lft[i] = 1;
        }
        rgt[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                rgt[i] = rgt[i + 1] + 1;
            }
            else
                rgt[i] = 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(rgt[i], lft[i]);
        }
        return sum;
    }
};