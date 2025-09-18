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

// Tabulation Approch

class Solution
{
public:
    int fn(vector<vector<int>> &arr, vector<vector<int>> &dp, int n)
    {
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int maxi = INT_MIN;
                for (int k = 0; k < 3; k++)
                {
                    if (j != k)
                    {
                        int curr = dp[i - 1][k] + arr[i][k];
                        maxi = max(maxi, curr);
                    }
                }
                dp[i][j] = maxi;
            }
        }
        return dp[n - 1][3];
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return fn(arr, dp, n);
    }
};

// Optimal Approch

class Solution
{
public:
    int fn(vector<vector<int>> &arr, vector<int> &dp, int n)
    {
        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        dp[3] = max({arr[0][0], arr[0][1], arr[0][2]});
        for (int i = 1; i < n; i++)
        {
            vector<int> temp(4);
            for (int j = 0; j < 4; j++)
            {
                int maxi = INT_MIN;
                for (int k = 0; k < 3; k++)
                {
                    if (j != k)
                    {
                        int curr = dp[k] + arr[i][k];
                        maxi = max(maxi, curr);
                    }
                }
                temp[j] = maxi;
            }
            dp = temp;
        }
        return dp[3];
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> dp(4);
        return fn(arr, dp, n);
    }
};
