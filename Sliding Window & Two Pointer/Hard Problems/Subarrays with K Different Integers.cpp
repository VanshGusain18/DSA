class Solution
{
public:
    int fn(vector<int> &nums, int k)
    {
        if (k <= 0)
            return 0;
        int cnt = 0, r = 0, l = 0;
        unordered_map<int, int> mp;
        while (r < nums.size())
        {
            mp[nums[r]]++;
            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (!mp[nums[l]])
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return fn(nums, k) - fn(nums, k - 1);
    }
};