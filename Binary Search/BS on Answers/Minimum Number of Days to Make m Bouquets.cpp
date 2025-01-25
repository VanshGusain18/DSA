// Brute Approch

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

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (m * k > n)
            return -1;
        int mini = findmin(bloomDay, n);
        int maxi = findmax(bloomDay, n);
        for (int i = mini; i <= maxi; i++)
        {
            int buq = 0, cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (bloomDay[j] <= i)
                {
                    cnt++;
                }
                else
                {
                    buq += cnt / k;
                    cnt = 0;
                }
            }
            buq += cnt / k;
            if (buq >= m)
                return i;
        }
        return -1;
    }
};

// Optimal Approch

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

    int noofbuq(vector<int> &bloomDay, int mid, int m, int k)
    {
        int buq = 0, cnt = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                cnt++;
            }
            else
            {
                buq = buq + cnt / k;
                cnt = 0;
            }
        }
        buq = buq + cnt / k;
        return buq;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long x = m;
        x *= k;
        if (x > n)
            return -1;
        int low = findmin(bloomDay, n);
        int high = findmax(bloomDay, n);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int nobq = noofbuq(bloomDay, mid, m, k);
            if (nobq >= m)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};