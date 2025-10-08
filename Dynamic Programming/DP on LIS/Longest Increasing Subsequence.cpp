// Recursive Approch

class Solution
{
public:
    int fn(vector<int> &nums, int idx, int prev)
    {
        if (idx == 0)
        {
            return nums[0] < prev;
        }
        int len = fn(nums, idx - 1, prev);
        if (nums[idx] < prev)
        {
            len = max(len, 1 + fn(nums, idx - 1, nums[idx]));
        }
        return len;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return fn(nums, n - 1, 1e9);
    }
};