// Brute Approch

class Solution
{
public:
    int fn(vector<int> &nums, int target, int idx)
    {
        if (idx == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target - nums[0] == 0 || target + nums[0] == 0)
                return 1;
            return 0;
        }
        int pos = fn(nums, target + nums[idx], idx - 1);
        int neg = fn(nums, target - nums[idx], idx - 1);
        return pos + neg;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return fn(nums, target, n - 1);
    }
};