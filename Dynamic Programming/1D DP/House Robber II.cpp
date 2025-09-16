class Solution
{
public:
    int rob2(vector<int> &nums)
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

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> temp, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                temp.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        return max(rob2(temp), rob2(temp2));
    }
};