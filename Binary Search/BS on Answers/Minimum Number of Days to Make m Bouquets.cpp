// Brute Approch

class Solution
{
public:
    bool possible(vector<int> &arr, int day, int m, int k)
    {
        int n = arr.size();
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int roseGarden(vector<int> arr, int k, int m)
    {
        long long val = m * 1ll * k * 1ll;
        int n = arr.size();
        if (val > n)
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        for (int i = mini; i <= maxi; i++)
        {
            if (possible(arr, i, m, k))
                return i;
        }
        return -1;
    }
};