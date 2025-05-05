// Brute Approch

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend <= INT_MIN && divisor == -1)
            return INT_MAX;
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        long long cnt = 0, temp = ldivisor;
        while (temp <= ldividend)
        {
            temp += ldivisor;
            cnt++;
        }
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
            return -cnt;
        return cnt;
    }
};

// Optimal Approch

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend <= INT_MIN && divisor == -1)
            return INT_MAX;
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        long long cnt = 0, temp = ldivisor;
        while (ldividend >= ldivisor)
        {
            long long temp = ldivisor, mul = 1;
            while (ldividend >= (temp << 1))
            {
                temp <<= 1;
                mul <<= 1;
            }
            ldividend -= temp;
            cnt += mul;
        }
        bool negative = (dividend < 0) ^ (divisor < 0);
        return negative ? -cnt : cnt;
    }
};