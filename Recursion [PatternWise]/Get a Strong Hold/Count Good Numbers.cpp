// Brute Approch

class Solution
{
public:
    bool isGood(int num, int length)
    {
        string str = to_string(num);
        while (str.length() < length)
        {
            str = "0" + str;
        }
        for (int i = 0; i < str.length(); i++)
        {
            int dig = str[i] - '0';
            if (i % 2 == 0)
            {
                if (dig % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if (dig == 0 || dig == 1 || dig == 4 || dig == 6 || dig == 8 || dig == 9)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int countGoodNumbers(long long n)
    {
        long long limit = 1;
        for (int i = 0; i < n; i++)
        {
            limit *= 10;
        }
        limit -= 1;
        int cnt = 0;
        for (int i = 0; i <= limit; i++)
        {
            if (isGood(i, n))
                cnt++;
        }
        return cnt;
    }
};

// Better Approch

class Solution
{
public:
    int countGoodNumbers(long long n)
    {
        const int MOD = 1e9 + 7;
        long long cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cnt *= 5;
            }
            else
            {
                cnt *= 4;
            }
            cnt %= MOD;
        }
        return cnt;
    }
};

// Optimal Approch

class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long myPow(long long x, long long n)
    {
        long long ans = 1.0;
        long nn = n;
        x %= MOD;
        if (nn < 0)
            nn = nn * -1;
        while (nn != 0)
        {
            if (nn % 2 == 0)
            {
                x = x * x % MOD;
                nn = nn / 2;
            }
            else
            {
                ans = ans * x % MOD;
                nn--;
            }
        }
        if (n < 0)
            return 1 / ans;
        return ans;
    }

    int countGoodNumbers(long long n)
    {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        return myPow(5, even) * myPow(4, odd) % MOD;
    }
};