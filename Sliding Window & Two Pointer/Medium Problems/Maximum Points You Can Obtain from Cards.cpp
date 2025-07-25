class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int maxi = 0, n = cardPoints.size();
        int lsum = 0, rsum = 0;
        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
        }
        maxi = lsum;
        int ridx = n - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[ridx];
            ridx--;
            maxi = max(maxi, lsum + rsum);
        }
        return maxi;
    }
};