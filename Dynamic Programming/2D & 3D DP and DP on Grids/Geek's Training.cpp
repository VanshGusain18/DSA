// Recursive Approch

class Solution
{
public:
    int fn(vector<vector<int>> &arr, int idx, int last)
    {
        if (idx == -1)
        {
            return 0;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int curr = arr[idx][i] + fn(arr, idx - 1, i);
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        int n = arr.size();
        return fn(arr, n - 1, -1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<vector<int>> &arr, vector<vector<int>> &dp, int idx, int last)
    {
        if (idx == -1)
            return 0;
        if (dp[idx][last + 1] != -1)
            return dp[idx][last + 1];
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int curr = arr[idx][i] + fn(arr, dp, idx - 1, i);
                maxi = max(maxi, curr);
            }
        }
        return dp[idx][last + 1] = maxi;
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return fn(arr, dp, n - 1, -1);
    }
};
