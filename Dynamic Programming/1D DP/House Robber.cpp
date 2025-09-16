// Recursive Approch

class Solution
{
public:
    int fn(vector<int> &nums, int idx)
    {
        if (idx == 0)
            return nums[idx];
        if (idx == -1)
            return 0;
        int pick = nums[idx] + fn(nums, idx - 2);
        int nPick = fn(nums, idx - 1);
        return max(pick, nPick);
    }

    int rob(vector<int> &nums)
    {
        return fn(nums, nums.size() - 1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &nums, vector<int> &dp, int idx)
    {
        if (idx == 0)
            return nums[idx];
        if (idx == -1)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + fn(nums, dp, idx - 2);
        int nPick = fn(nums, dp, idx - 1);
        return max(pick, nPick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fn(nums, dp, n - 1);
    }
};

// Tabulation Approch

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            int nPick = dp[i - 1];
            dp[i] = max(pick, nPick);
        }
        return dp[n - 1];
    }
};

// Optimal Approch

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += prev2;
            }
            int nPick = prev;
            int curr = max(pick, nPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};