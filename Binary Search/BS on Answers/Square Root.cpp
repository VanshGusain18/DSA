class Solution
{
public:
    int floorSqrt(int n)
    {
        // Your code goes here
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mid * mid > n)
                high = mid - 1;
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
};