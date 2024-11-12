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