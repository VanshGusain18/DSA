// Brute Approch

class Solution
{
public:
    int findXOR(int l, int r)
    {
        // complete the function here
        int x = 0;
        for (int i = l; i <= r; i++)
        {
            x ^= i;
        }
        return x;
    }
};

// Optimal Approch

class Solution
{
public:
    int xrr(int n)
    {
        if (n % 4 == 0)
            return n;
        else if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else
            return 0;
    }

    int findXOR(int l, int r)
    {
        // complete the function here
        int xl = xrr(l - 1);
        int xr = xrr(r);
        return xl ^ xr;
    }
};