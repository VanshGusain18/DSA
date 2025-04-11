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

// Optimal Approch

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long nn = n;
        if (nn < 0)
            nn = nn * -1;
        while (nn != 0)
        {
            if (nn % 2 == 0)
            {
                x = x * x;
                nn = nn / 2;
            }
            else
            {
                ans = ans * x;
                nn--;
            }
        }
        if (n < 0)
            return 1 / ans;
        return ans;
    }
};