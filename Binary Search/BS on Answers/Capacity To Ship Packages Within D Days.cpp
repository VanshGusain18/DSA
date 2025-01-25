class Solution
{
public:
    int finddays(vector<int> weights, int cap, int n)
    {
        int days = 1;
        int load = 0;
        for (int i = 0; i < n; i++)
        {
            if (load + weights[i] > cap)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int res = finddays(weights, mid, n);
            if (res > days)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};