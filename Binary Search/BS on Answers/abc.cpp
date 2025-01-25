class Solution
{
public:
    int findmin(const vector<int> &bloomDay, int n)
    {
        int mini = bloomDay[0];
        for (int i = 1; i < n; ++i)
        {
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }

    int findmax(const vector<int> &bloomDay, int n)
    {
        int maxi = bloomDay[0];
        for (int i = 1; i < n; ++i)
        {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }

    int findres(vector<int> &nums, int n, int mid)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            double x = (float)nums[i] / mid;
            res = res + ceil(x);
        }
        return res;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        if (n > threshold)
            return -1;
        int low = 1;
        int high = findmax(nums, n);
        if (n == threshold)
            return high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int res = findres(nums, n, mid);
            if (res > threshold)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};