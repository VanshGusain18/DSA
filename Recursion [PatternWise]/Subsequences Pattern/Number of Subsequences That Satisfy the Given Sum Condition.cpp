// Recursive Approch

class Solution
{
public:
    void func(vector<int> &nums, int mini, int maxi, int i, int &cnt, int target, bool taken)
    {
        if (i == nums.size())
        {
            if (taken && maxi + mini <= target)
            {
                cnt++;
            }
            return;
        }
        func(nums, min(mini, nums[i]), max(maxi, nums[i]), i + 1, cnt, target, true);
        func(nums, mini, maxi, i + 1, cnt, target, taken);
    }

    int numSubseq(vector<int> &nums, int target)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        int cnt = 0;
        func(nums, mini, maxi, 0, cnt, target, false);
        return cnt;
    }
};