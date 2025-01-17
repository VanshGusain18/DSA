// Brute Force

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long temp = nums[j];
                temp *= 2;
                if (nums[i] > temp)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};