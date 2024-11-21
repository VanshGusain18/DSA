// Brute Approch

class Solution
{
public:
    bool lsearch(vector<int> a, int n)
    {
        bool f = false;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == n)
            {
                f = true;
                break;
            }
        }
        return f;
    }

    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size(), len = 1, maxLen = 1;
        if (!n)
            return 0;
        for (int i = 0; i < n; i++)
        {
            len = 1;
            int x = nums[i];
            while (lsearch(nums, x + 1))
            {
                len++;
                x++;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};