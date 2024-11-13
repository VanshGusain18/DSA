// Brute Force Approch

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = INT_MIN, max = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                curr = 0;
                for (int k = i; k <= j; k++)
                {
                    curr += nums[k];
                }
                if (max < curr)
                {
                    max = curr;
                }
            }
        }
        return max;
    }
};

// Better Approch

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = INT_MIN, max = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            curr = 0;
            for (int j = i; j < n; j++)
            {
                curr += nums[j];
                if (curr > max)
                {
                    max = curr;
                }
            }
        }
        return max;
    }
};

// Optimal Approch (Kadane's Algorithm)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = INT_MIN, max = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (curr < 0)
            {
                curr = 0;
            }
            curr += nums[i];
            if (curr > max)
            {
                max = curr;
            }
        }
        return max;
    }
};