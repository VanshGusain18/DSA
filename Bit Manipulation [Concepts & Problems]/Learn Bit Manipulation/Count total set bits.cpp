// Brute Approch

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int cntb(int n)
    {
        int cnt = 0;
        while (n > 1)
        {
            if (n % 2)
                cnt++;
            n /= 2;
        }
        if (n == 1)
            cnt++;
        return cnt;
    }
    int countSetBits(int n)
    {
        // Your logic here
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += cntb(i);
        }
        return cnt;
    }
};

// Optimal Approch

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int cntb(int n)
    {
        int cnt = 0;
        while (n > 1)
        {
            if (n & 1)
                cnt++;
            n = n >> 1;
        }
        if (n == 1)
            cnt++;
        return cnt;
    }
    int countSetBits(int n)
    {
        // Your logic here
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += cntb(i);
        }
        return cnt;
    }
};