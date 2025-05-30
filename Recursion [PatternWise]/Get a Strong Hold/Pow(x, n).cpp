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

// Recursive Approch

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long nn = n;
        if (nn < 0)
        {
            return 1.0 / myPow(x, -nn);
        }
        if (nn == 0)
        {
            return 1.0;
        }
        if (nn % 2 == 0)
        {
            return myPow(x * x, nn / 2);
        }
        else
        {
            return x * myPow(x, nn - 1);
        }
    }
};

// Optimal Recursive Approch

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long nn = n;
        if (nn < 0)
        {
            x = 1 / x;
            nn = -nn;
        }
        if (nn == 0)
            return 1.0;
        double half = myPow(x, nn / 2);
        if (nn % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};