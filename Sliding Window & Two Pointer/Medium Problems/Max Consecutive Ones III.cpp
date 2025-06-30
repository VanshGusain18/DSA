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