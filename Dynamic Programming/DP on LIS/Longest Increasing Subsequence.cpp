// Recursive Approch

class Solution
{
public:
    int fn(vector<int> &nums, int idx, int prev)
    {
        if (idx == nums.size())
            return 0;
        int notTake = fn(nums, idx + 1, prev);
        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev])
        {
            take = 1 + fn(nums, idx + 1, idx);
        }
        return max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        return fn(nums, 0, -1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];
        int notTake = fn(nums, idx + 1, prev, dp);
        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev])
            take = 1 + fn(nums, idx + 1, idx, dp);
        return dp[idx][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fn(nums, 0, -1, dp);
    }
};

// Tabulation Approch

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int notTake = dp[i + 1][j + 1];
                int take = 0;
                if (j == -1 || nums[i] > nums[j])
                {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][j + 1] = max(notTake, take);
            }
        }

        return dp[0][0];
    }
};

// Binary Search Approch

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                l++;
            }
            else
            {
                auto idx = lower_bound(temp.begin(), temp.end(), nums[i]);
                *idx = nums[i];
            }
        }
        return l;
    }
};
