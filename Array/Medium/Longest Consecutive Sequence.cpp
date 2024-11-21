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

// Better Approch

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size(), len = 1, maxLen = 1, x = INT_MIN;
        if (!n)
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == x)
            {
                len++;
                x = nums[i];
            }
            else if (nums[i] != x)
            {
                len = 1;
                x = nums[i];
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

// Optimal Approch

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size(), len = 1, maxLen = 1, x = INT_MIN;
        if (!n)
            return 0;
        unordered_set<int> eles;
        for (int i = 0; i < n; i++)
        {
            eles.insert(nums[i]);
        }
        for (auto it : eles)
        {
            if (eles.find(it - 1) == eles.end())
            {
                len = 1;
                int x = it;
                while (eles.find(x + 1) != eles.end())
                {
                    len++;
                    x++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};