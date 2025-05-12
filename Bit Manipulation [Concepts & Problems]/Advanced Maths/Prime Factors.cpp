class Solution
{
public:
    vector<int> AllPrimeFactors(int N)
    {
        // Code here
        vector<int> res;
        for (int i = 2; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                res.push_back(i);
                while (N % i == 0)
                {
                    N /= i;
                }
            }
        }
        if (N != 1)
            res.push_back(N);
        return res;
    }
};