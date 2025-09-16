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