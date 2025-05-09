class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long xr = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            xr ^= nums[i];
        }
        int diff = (xr & (xr - 1)) ^ xr;
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (diff & nums[i])
                res1 ^= nums[i];
            else
                res2 ^= nums[i];
        }
        return {res1, res2};
    }
};