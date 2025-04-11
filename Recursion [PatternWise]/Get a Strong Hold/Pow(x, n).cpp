// Brute Approch

class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1;
        long nn = n;
        if (nn < 0)
            nn = nn * -1;
        for (int i = 0; i < nn; i++)
        {
            res *= x;
        }
        if (n > 0)
        {
            return res;
        }
        return 1 / res;
    }
};