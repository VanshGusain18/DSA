class Solution
{
public:
    bool fn(vector<int> &arr, int k, int i, int sum)
    {
        if (i == arr.size())
        {
            return sum == k;
        }
        if (sum > k)
        {
            return false;
        }
        if (fn(arr, k, i + 1, sum + arr[i]))
        {
            return true;
        }
        if (fn(arr, k, i + 1, sum))
        {
            return true;
        }
        return false;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return fn(arr, k, 0, 0);
    }
};

// Itrative Approch

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        int count = 0;

        for (int mask = 1; mask < (1 << n); ++mask)
        {
            int mini = INT_MAX, maxi = INT_MIN;

            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    mini = min(mini, nums[i]);
                    maxi = max(maxi, nums[i]);
                }
            }

            if (mini + maxi <= target)
            {
                count++;
            }
        }

        return count;
    }
};