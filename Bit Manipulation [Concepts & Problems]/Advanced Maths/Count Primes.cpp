class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<int> prim(n, 1);
        for (int i = 2; i * i < n; i++)
        {
            if (prim[i] == 1)
            {
                for (int j = i * i; j < n; j += i)
                {
                    prim[j] = 0;
                }
            }
        }
        return count(prim.begin() + 2, prim.end(), 1);
    }
};