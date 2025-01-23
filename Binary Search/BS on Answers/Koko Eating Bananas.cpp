// Brute Approch

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        double result = INT_MAX, speed = 0;
        while (result > h)
        {
            result = 0;
            speed++;
            for (int i = 0; i < n; i++)
            {
                float x = (float)piles[i] / speed;
                result += ceil(x);
            }
        }
        return speed;
    }
};