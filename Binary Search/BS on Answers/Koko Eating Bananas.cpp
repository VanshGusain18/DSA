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

// Optimal Approch

class Solution
{
public:
    double fn(vector<int> piles, int m, int n)
    {
        double result = 0;
        for (int i = 0; i < n; i++)
        {
            float x = (float)piles[i] / m;
            result += ceil(x);
        }
        return result;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, piles[i]);
        }
        int low = 0, high = maxi;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (fn(piles, mid, n) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};