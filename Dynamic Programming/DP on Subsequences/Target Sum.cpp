// Brute Approch

class Solution
{
public:
    int fn(vector<int> &nums, int idx, int target)
    {
        if (idx == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        int notTake = fn(nums, idx - 1, target);
        int take = 0;
        if (nums[idx] <= target)
        {
            take = fn(nums, idx - 1, target - nums[idx]);
        }
        return take + notTake;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int subsetSum = (totalSum + target) / 2;
        int n = nums.size();
        return fn(nums, n - 1, subsetSum);
    }
};

// Memoization Approch

class Solution
{
public:
    int countSubsets(vector<int> &nums, int idx, int target, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = countSubsets(nums, idx - 1, target, dp);
        int take = 0;
        if (nums[idx] <= target)
        {
            take = countSubsets(nums, idx - 1, target - nums[idx], dp);
        }

        return dp[idx][target] = take + notTake;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int subsetSum = (totalSum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, -1));

        return countSubsets(nums, n - 1, subsetSum, dp);
    }
};
