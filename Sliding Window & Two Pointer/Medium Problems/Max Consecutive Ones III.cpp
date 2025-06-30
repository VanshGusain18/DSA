// Brute Approch

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            int z = 0;
            for (int j = i; j < n; j++)
            {
                if (!nums[j])
                    z++;
                if (z <= k)
                {
                    int len = j - i + 1;
                    res = max(res, len);
                }
                else
                    break;
            }
        }
        return res;
    }
};

// Optimal Approch

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int res = 0, l = 0, r = 0, z = 0;
        while (r < nums.size())
        {
            if (!nums[r])
                z++;
            while (z > k)
            {
                if (!nums[l])
                    z--;
                l++;
            }
            int len = r - l + 1;
            res = max(res, len);
            r++;
        }
        return res;
    }
};