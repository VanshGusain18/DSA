class Solution
{
public:
    int fn(int mid, int n)
    {
        long long result = 1;
        for (int i = 0; i < n; i++)
        {
            result *= mid;
            if (result > INT_MAX)
                return result;
        }
        return result;
    }

    int nthRoot(int n, int m)
    {
        // Code here.
        int low = 1, high = m;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (fn(mid, n) == m)
                return mid;
            else if (fn(mid, n) > m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};